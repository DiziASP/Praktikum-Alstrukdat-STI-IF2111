#include "linkdummy.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L)
{
    return First(L) == Last(L);
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L)
{
    address pDummy = Alokasi(0);
    if (pDummy != Nil)
    {
        First(*L) = pDummy;
        Last(*L) = pDummy;
    }
    else
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi(ElType X)
{
    address P = (address)malloc(sizeof(Node));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi(address P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X)
{
    address P = First(L);
    address pDummy = Last(L);
    while (P != pDummy && Info(P) != X)
    {
        P = Next(P);
    }
    return P != pDummy ? P : Nil;
}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X)
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X)
{
    if (IsEmpty(*L))
    {
        InsertFirst(L, X);
    }
    else
    {
        address P = Alokasi(X);
        if (P != Nil)
        {
            address last = First(*L);
            while (Info(Next(last)) != 0)
            {
                last = Next(last);
            }
            Next(last) = P;
            Next(P) = Last(*L);
        }
    }
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X)
{
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(First(*L));
    Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X)
{
    address last, precLast;
    /* Algoritma */
    last = First(*L);
    precLast = Nil;
    while (Next(last) != Last(*L))
    {
        precLast = last;
        last = Next(last);
    }
    *X = Info(last);
    if (precLast == Nil)
    { /* kasus satu elemen */
        First(*L) = Last(*L);
    }
    else
    {
        Next(precLast) = Last(*L);
    }
    free(last);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */