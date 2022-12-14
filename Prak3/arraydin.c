#include "arraydin.h"
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin Arr;
    Arr.A = (ElType *) malloc(InitialSize * sizeof(ElType));
    Arr.Capacity = InitialSize;
    Arr.Neff = 0;
    return Arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    if (array->Neff == array->Capacity){
        array->Capacity *= 2;
        array->A = (ElType *) realloc(array->A, array->Capacity * sizeof(ElType));
    }

    int j;
    for (j = array->Neff; j > i; j--){
        array->A[j] = array->A[j-1];
    }
    
    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el){
    InsertAt(array, el, array->Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    int j;
    for (j = i; j < array->Neff-1; j++){
        array->A[j] = array->A[j+1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array){
    DeleteAt(array, array->Neff-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
    if(IsEmpty(array)){
        printf("[]\n");
    }
    else{
        printf("[");
        int i;
        for (i = 0; i < array.Neff-1; i++){
            printf("%d, ", array.A[i]);
        }
        printf("%d", array.A[array.Neff-1]);
        printf("]\n");
    }
    
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
    int i = 0, j = array->Neff-1;
    int temp;
    while(i < j){
        temp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = temp;
        i++;
        j--;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
    ArrayDin newArr = MakeArrayDin();
    int i;
    for (i = 0; i < array.Neff; i++){
        InsertLast(&newArr, array.A[i]);
    }
    return newArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
    int i;
    for (i = 0; i < array.Neff; i++){
        if (array.A[i] == el){
            return i;
        }
    }
    return -1;
}