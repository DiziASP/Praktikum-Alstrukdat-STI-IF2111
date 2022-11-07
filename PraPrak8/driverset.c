#include "set.h"
#include <stdio.h>

int main()
{
    Set S1, S2, S3, S4, S5, S6;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    CreateEmpty(&S4);

    for (int i = 0; i < 10; i++)
    {
        Insert(&S1, i);
        Insert(&S2, i + 3);
    }

    PrintSet(S1);
    printf(" U ");
    PrintSet(S2);
    printf(" = ");

    Union(&S1, &S2, &S3);
    PrintSet(S3);

    PrintSet(S1);
    printf(" n ");
    PrintSet(S2);
    printf(" = ");

    Intersection(&S1, &S2, &S3);
    PrintSet(S3);

    PrintSet(S1);
    printf(" - ");
    PrintSet(S2);
    printf(" = ");

    Difference(&S1, &S2, &S3);
    PrintSet(S3);

    Insert(&S4, 3);
    Insert(&S4, 4);
    Insert(&S4, 5);
    Insert(&S4, 4);
    Insert(&S4, 9);

    PrintSet(S4);

    printf(" is Subset? ");
    printf(IsSubset(S4, S1) ? "Yes\n" : "No\n");

    printf(" is Equal? ");
    printf(IsEqual(S4, S1) ? "Yes\n" : "No\n");
    return 0;
}