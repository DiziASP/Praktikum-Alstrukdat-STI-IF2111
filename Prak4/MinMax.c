#include "MinMax.h"

int FindIdxMax(List L)
{
    int max = 0, idx = 0;
    for (IdxType i = FirstIdx(L); i <= LastIdx(L); i++)
    {
        if (L.A[i] > max)
        {
            max = L.A[i];
            idx = i;
        }
    }
    return idx;
}

int FindIdxMin(List L)
{
    int min = 0, idx = 0;
    for (IdxType i = FirstIdx(L); i <= LastIdx(L); i++)
    {
        if (L.A[i] < min)
        {
            min = L.A[i];
            idx = i;
        }
    }
    return idx;
}

List MinMax(List L)
{

    IdxType min = FindIdxMin(L);
    InsertLast(&L, Get(L, min));
    DeleteAt(&L, min);

    IdxType max = FindIdxMax(L);
    InsertLast(&L, Get(L, max));
    DeleteAt(&L, max);

    return L;
}