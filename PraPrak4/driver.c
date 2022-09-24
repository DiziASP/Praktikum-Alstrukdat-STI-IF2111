#include <stdio.h>
#include "list.h"

void PrintList(List anjay)
{
    int i;
    for (i = 0; i < Length(anjay); i++)
    {
        printf("%d ", Get(anjay, i));
    }
    printf("\n");
}

int main()
{
    List L = MakeList();

    InsertLast(&L, 1);
    InsertLast(&L, 2);
    InsertLast(&L, 3);
    InsertLast(&L, 4);
    InsertLast(&L, 5);
    PrintList(L);

    printf("%d\n", Length(L));

    DeleteLast(&L);
    PrintList(L);

    DeleteFirst(&L);
    PrintList(L);

    DeleteAt(&L, 2);
    PrintList(L);

    InsertFirst(&L, 1);
    PrintList(L);

    InsertAt(&L, 3, 2);
    PrintList(L);

    InsertLast(&L, 5);
    PrintList(L);

    printf("%d\n", Search(L, 3));
    printf("%d\n", Search(L, 6));

    List L2 = MakeList();
    InsertLast(&L2, 6);
    InsertLast(&L2, 7);
    InsertLast(&L2, 8);
    InsertLast(&L2, 9);
    InsertLast(&L2, 10);
    PrintList(Concat(L, L2));
    return 0;
}