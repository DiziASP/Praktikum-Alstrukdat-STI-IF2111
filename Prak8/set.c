#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
{
    S->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
{
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S)
{
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

int length(Set S)
{
    return S.Count;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
{
    if (!IsMember(*S, Elmt))
    {
        S->Elements[S->Count] = Elmt;
        S->Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt)
{
    int i = 0;
    while (i < S->Count && S->Elements[i] != Elmt)
    {
        i++;
    }
    // if (i < S->Count)
    // {
    //     S->Elements[i] = S->Elements[S->Count - 1];
    //     S->Count--;
    // } // Versi 1
    while (i < S->Count - 2)
    {
        S->Elements[i] = S->Elements[i + 1];
        i++;
    }
    S->Count--;
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt)
{
    int i = 0;
    while (i < S.Count && S.Elements[i] != Elmt)
    {
        i++;
    }
    return i < S.Count;
}
/* Mengembalikan true jika Elmt adalah member dari S */

/* ********** Primitif Dasar Set ********* */
void Union(Set *S1, Set *S2, Set *S3)
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count && !IsFull(*S3))
    {
        if (!IsMember(*S3, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }

    int j = 0;
    while (j < S2->Count && !IsFull(*S3))
    {
        if (!IsMember(*S3, S2->Elements[j]))
        {
            Insert(S3, S2->Elements[j]);
        }
        j++;
    }
}

void Intersection(Set *S1, Set *S2, Set *S3)
{
    CreateEmpty(S3);

    int i = 0;
    while (i < S1->Count && !IsFull(*S3))
    {
        if (IsMember(*S2, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }
}

void Difference(Set *S1, Set *S2, Set *S3)
{
    CreateEmpty(S3);

    int i = 0;
    while (i < S1->Count && !IsFull(*S3))
    {
        if (!IsMember(*S2, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }
}

void PrintSet(Set S)
{
    printf("{");
    for (int i = 0; i < S.Count; i++)
    {
        printf("%d", S.Elements[i]);
        if (i < S.Count - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

/* ********** Operasi Lain ********* */
void CopySet(Set Sin, Set *Sout)
{
    int i = 0;
    while (i < Sin.Count && !IsFull(*Sout))
    {
        Insert(Sout, Sin.Elements[i]);
        i++;
    }
}

boolean IsSubset(Set S1, Set S2)
{
    int i = 0;
    boolean flag = true;
    while (i < S1.Count && flag == true)
    {
        if (!IsMember(S2, S1.Elements[i]))
        {
            flag = false;
        }
        i++;
    }
    return flag;
}

boolean IsEqual(Set S1, Set S2)
{
    return IsSubset(S1, S2) && IsSubset(S2, S1);
}