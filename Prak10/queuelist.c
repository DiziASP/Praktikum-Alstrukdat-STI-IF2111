#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X)
{
    *P = (address)malloc(sizeof(ElmtQueue));
    if (*P != Nil)
    {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi(address P)
{
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty(Queue Q)
{
    return Head(Q) == Nil && Tail(Q) == Nil;
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q)
{
    int count = 0;
    address p = Head(Q);
    while (p != Nil)
    {
        count++;
        p = Next(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue *Q)
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X)
{
    address p;
    Alokasi(&p, X);
    if (p != Nil)
    {
        if (IsEmpty(*Q))
        {
            Head(*Q) = p;
        }
        else
        {
            Next(Tail(*Q)) = p;
        }
        Tail(*Q) = p;
    }
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Dequeue(Queue *Q, infotype *X)
{
    address p;
    if (!IsEmpty(*Q))
    {
        *X = InfoHead(*Q);
        p = Head(*Q);
        Head(*Q) = Next(Head(*Q));
        Next(p) = Nil;
        if (Head(*Q) == Nil)
        {
            Tail(*Q) = Nil;
        }
        Dealokasi(p);
    }
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */