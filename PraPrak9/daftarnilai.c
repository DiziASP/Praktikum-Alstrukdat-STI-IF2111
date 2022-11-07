#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    List L;
    address p;
    CreateEmpty(&L);
    infotype input;

    while (true)
    {
        scanf("%d", &input);
        if (input < 0 || input > 100)
            break;
        InsVLast(&L, input);
    }

    if (IsEmpty(L))
        printf("Daftar nilai kosong\n");
    else
    {
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));

        PrintInfo(L);
        printf("\n");

        /*Inverted */
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    }
    return 0;
}