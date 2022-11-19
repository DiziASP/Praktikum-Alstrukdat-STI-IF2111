#include "linkdummy.h"
#include <stdio.h>

int main()
{
    List L;
    MakeEmpty(&L);
    printf("%d\n", IsEmpty(L));

    InsertLast(&L, 1);
    printf("%d\n", IsEmpty(L));

    InsertFirst(&L, 2);
    InsertLast(&L, 3);
    InsertFirst(&L, 4);
    InsertLast(&L, 5);
    InsertFirst(&L, 6);

    printf("%d\n", Info(Search(L, 3)));

    ElType X;
    DeleteFirst(&L, &X);
    printf("%d\n", X);

    DeleteLast(&L, &X);
    printf("%d\n", X);

    return 0;
}
