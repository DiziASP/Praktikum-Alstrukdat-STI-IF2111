#include "mesinkarakter.h"

int hitungkarakter(char karakter)
{
    int count = 0;
    START();
    while (IsEOP() == false)
    {
        if (GetCC() == karakter)
        {
            count++;
        }
        ADV();
    }
    return count;
}