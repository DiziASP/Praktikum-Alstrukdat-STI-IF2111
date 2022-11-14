/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r)
{
    /* Kamus Lokal */
    address P;
    int i;
    /* Algoritma */
    P = First(L);
    i = 0;
    while (i < r)
    {
        P = Next(P);
        i++;
    }
    return Info(P);
}

int main()
{
    List L;
    int r;
    /* Tuliskan implementasi di sini */
    CreateEmpty(&L);
    do
    {
        scanf("%d", &r);
        if (r > 0)
        {
            InsVLast(&L, r);
        }
    } while (r > 0);

    scanf("%d", &r);
    if (IsEmpty(L))
    {
        printf("List Kosong\n");
    }
    else
    {

        printf("%d\n", ElemenKeN(L, r));
    }
    return 0;
}