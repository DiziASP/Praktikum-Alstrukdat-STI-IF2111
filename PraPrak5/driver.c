#include <stdio.h>
#include "mesinkata.h"

int main()
{
    STARTWORD();
    while (!EndWord)
    {
        for (int i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
    return 0;
}