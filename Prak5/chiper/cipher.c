#include <stdio.h>
#include "boolean.h"
#include "mesinkarakterv2.h"
#include "mesinkata.h"

int main()
{
    STARTWORD();
    int nFirstWord = currentWord.Length, i;
    while (!isEndWord())
    {
        i = 0;
        while (i < currentWord.Length)
        {
            currentWord.TabWord[i] = (currentWord.TabWord[i] - 'A' + nFirstWord) % 26 + 'A';
            printf("%c", currentWord.TabWord[i]);
            i++;
        }
        ADVWORD();
        if (!isEndWord() || currentWord.Length == 0)
            printf(" ");
    }
    printf(".\n");
    return 0;
}