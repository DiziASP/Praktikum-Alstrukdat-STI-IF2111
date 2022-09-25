#include <stdio.h>
#include "array.h"

int main()
{
    TabInt T;
    /* ********** KONSTRUKTOR ********** */
    MakeEmpty(&T);

    // printf("Elemen Efektif : %d\n", NbElmt(T));

    // /* ********** TEST FUNGSI DAN PROSEDUR ********** */
    // /* *** Test IsEmpty *** */
    // printf("IsEmpty : %d\n", IsEmpty(T));

    /* *** Test SetEl dan SetNeff *** */
    SetNeff(&T, 40);
    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        SetEl(&T, i, i);
    }

    /* *** Test GetEl *** */
    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        printf("T[%d] = %d\n", i, GetElmt(T, i));
    }
    // /* *** Test IsFull *** */
    // printf("IsFull : %d\n", IsFull(T));

    // /* *** Test IsIdxValid *** */
    // printf("IsIdxValid-true: %d\n", IsIdxValid(T, 1));     // true
    // printf("IsIdxValid-false : %d\n", IsIdxValid(T, 302)); // false

    // /* *** Test IsIdxEff *** */
    // printf("IsIdxEff-true : %d\n", IsIdxEff(T, 1));   // true
    // printf("IsIdxEff-false : %d\n", IsIdxEff(T, 95)); // false

    /* *** Test SetTab *** */
    // TabInt T2;
    // MakeEmpty(&T2);
    // SetTab(T, &T2);

    // /* *** Test PlusTab  & MinusTab *** */
    // TabInt T3 = PlusTab(T, T2);
    // printf("Test Fungsi PlusTab\n");
    // for (IdxType i = GetFirstIdx(T3); i <= GetLastIdx(T3); i++)
    // {
    //     printf("T3[%d] = %d\n", i, GetElmt(T3, i));
    // }

    // TabInt T4 = MinusTab(T, T2);
    // printf("Test Fungsi MinusTab\n");
    // for (IdxType i = GetFirstIdx(T4); i <= GetLastIdx(T4); i++)
    // {
    //     printf("T4[%d] = %d\n", i, GetElmt(T4, i));
    // }

    // /* *** Test ValMax *** */
    // printf("Test Fungsi ValMax : %d\n", ValMax(T));

    // /* *** Test ValMin *** */
    // printf("Test Fungsi ValMin : %d\n", ValMin(T));

    // /* *** Test IdxMaxTab *** */
    // printf("Test Fungsi IdxMaxTab : %d\n", IdxMaxTab(T));

    // /* *** Test IdxMinTab *** */
    // printf("Test Fungsi IdxMinTab : %d\n", IdxMinTab(T));

    /* *** Test TulisIsi *** */
    // printf("Test Prosedur TulisIsi\n");
    // TulisIsi(T);

    // TabInt T3 = PlusTab(T, T2);
    // // TabInt T5;
    // // MakeEmpty(&T5);
    // TulisIsi(T3);
    return 0;
}