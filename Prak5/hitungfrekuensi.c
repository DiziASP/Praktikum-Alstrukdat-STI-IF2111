#include "hitungfrekuensi.h"

int hitungfrekuensi()
{
    START();
    int count = 0;
    while (!IsEOP())
    {
        if (currentChar == 'T' || currentChar == 't')
        {
            ADV();
            if (currentChar == 'I' || currentChar == 'i')
            {
                ADV();
                if (currentChar == 'G' || currentChar == 'g')
                {
                    ADV();
                    if (currentChar == 'A' || currentChar == 'a')
                    {
                        count++;
                    }
                }
            }
        }

        ADV();
    }
    return count;
}