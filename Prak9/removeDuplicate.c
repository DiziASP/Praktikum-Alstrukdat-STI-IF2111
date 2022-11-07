#include "removeDuplicate.h"
#include <stdlib.h>
#include <stdio.h>

void SortList(List *L)
{
    address P, Q;
    infotype temp;
    P = First(*L);
    while (P != Nil)
    {
        Q = Next(P);
        while (Q != Nil)
        {
            if (Info(P) > Info(Q))
            {
                temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;
            }
            Q = Next(Q);
        }
        P = Next(P);
    }
}

List removeDuplicate(List l){
    address P = First(l);
    List lRes;
    CreateEmpty(&lRes);

    while (P != Nil)
    {
        if (Search(lRes, P->info) == Nil)
        {
            InsVLast(&lRes, Info(P));
        }
        P = Next(P);
    }
    SortList(&lRes);
    return lRes;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/