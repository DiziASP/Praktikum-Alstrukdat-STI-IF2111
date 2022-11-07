#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    List l;
    CreateEmpty(&l);
    int i, x, N, NOper;
    scanf("%d", &N);
	for (int i = 0; i < N; i++)
    {
        InsVLast(&l, i + 1);
    }
    scanf("%d", &NOper);
    for (i = 0; i < NOper; i++)
    {
        scanf("%d", &x);
        infotype val;
        if (Search(l, x) != Nil)
        {
            DelP(&l, x);
            InsVFirst(&l, x);
            printf("hit ");
            PrintInfo(l);
            printf("\n");

        }
        else
        {
            DelVLast(&l, &val);
            InsVFirst(&l, x);
            printf("miss ");
            PrintInfo(l);
            printf("\n");
        }     
    }
    return 0;
}   