#include "listsirkuler.h"
#include <stdio.h>

int main()
{
    List L;
    CreateEmpty(&L);
    printf("IsEmpty(L) = %d\n", IsEmpty(L));

    InsertLast(&L, Alokasi(1));
    InsertLast(&L, Alokasi(2));
    InsertLast(&L, Alokasi(3));
    InsertLast(&L, Alokasi(4));
    InsertLast(&L, Alokasi(5));
    InsertLast(&L, Alokasi(6));

    printf("Initial Value\n");
    InsVFirst(&L, 7);
    PrintInfo(L);
    printf("\n");

    printf("Insert Last\n");
    InsVLast(&L, 8);
    PrintInfo(L);
    printf("\n");

    printf("Delete 8\n");
    DelP(&L, 8);
    PrintInfo(L);
    printf("\n");

    printf("Insert Last\n");
    InsVLast(&L, 8);
    PrintInfo(L);
    printf("\n");

    printf("Insert After\n");
    address P = Alokasi(9);
    InsertAfter(&L, P, Search(L, 5));
    PrintInfo(L);
    printf("\n");

    infotype X;
    DelVFirst(&L, &X);
    PrintInfo(L);
    printf("\n");

    DelP(&L, 2);
    PrintInfo(L);
    printf("\n");

    DelLast(&L, &P);
    printf("X = %d\n", Info(P));
    PrintInfo(L);
    printf("\n");

    return 0;
}