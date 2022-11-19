#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str = "ck2hi3ersfotm1p0Eh";

    char *query = (char *)malloc(7 * sizeof(char));
    scanf("%s", query);

    char *res = (char *)malloc(7 * sizeof(char));
    for (int i = 0; i < 6; i++)
    {
        int idx = query[i] & 0xf;
        res[i] = str[idx];
    }

    printf("%s\n", res);
    return 0;
}