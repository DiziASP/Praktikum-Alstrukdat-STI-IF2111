#include "hashmap.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M)
{
    M->Count = Nil;
    for (int i = 0; i < MaxEl; i++)
    {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K)
{
    return K % MaxEl;
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k)
{
    address i = Hash(k);
    while (M.Elements[i].Key != k && M.Elements[i].Key != Undefined)
    {
        i = (i + 1) % MaxEl;
    }
    if (M.Elements[i].Key == k)
    {
        return M.Elements[i].Value;
    }
    else
    {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v)
{
    address i = Hash(k);
    while (M->Elements[i].Key != Undefined)
    {
        i = (i + 1) % MaxEl;
    }
    M->Elements[i].Key = k;
    M->Elements[i].Value = v;
    M->Count++;
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing jika index sudah terisi    */

void Delete(HashMap *M, keytype k)
{
    address i = Hash(k);
    while (M->Elements[i].Key != k && M->Elements[i].Key != Undefined)
    {
        i = (i + 1) % MaxEl;
    }
    if (M->Elements[i].Key == k)
    {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
        M->Count--;
    }
}
/* Menghapus Elmt dari HashMap M. */
/* I.S. M tidak kosong
        M mungkin berisi v dengan key k */
/* F.S. v tidak menjadi anggota dari M dengan key k. Jika k tidak ada, operasi tidak dilakukan
        gunakan open addressing jika index yang dihapus sudah terisi    */

void PrintHashMap(HashMap M)
{
    for (int i = 0; i < MaxEl; i++)
    {
        if (M.Elements[i].Key != Undefined)
        {
            printf("%d:%d\n", M.Elements[i].Key, M.Elements[i].Value);
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. M ditampilkan ke layar */