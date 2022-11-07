#include "OddEvenList.h"
#include <stdio.h>

int main()
{
    List L1, L2, L3;
    infotype X;
    address P;
    int i;
    CreateEmpty(&L1);
    for (i = 1; i <= 5; i++)
    {
        X = i * 2;
        InsVFirst(&L1, X);
        X = i * 4 - 1;
        InsVFirst(&L1, X);
    }
    PrintInfo(L1);
    printf("\n");

    OddEvenList(L1, &L2, &L3);
    PrintInfo(L2);
    printf("\n");
    PrintInfo(L3);
    printf("\n");
    return 0;
}