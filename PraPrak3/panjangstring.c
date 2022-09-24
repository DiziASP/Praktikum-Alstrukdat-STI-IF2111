#include "panjangstring.h"

int panjangString(char *str)
{
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}