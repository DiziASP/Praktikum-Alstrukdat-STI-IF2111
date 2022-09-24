#include <stdio.h>

int main()
{
    char str[10];
    char freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int i;
    scanf("%s", str);

    for (i = 0; i < 10; i++){
        if (str[i] == '0') freq[0]++;
        else if (str[i] == '1') freq[1]++;
        else if (str[i] == '2') freq[2]++;
        else if (str[i] == '3') freq[3]++;
        else if (str[i] == '4') freq[4]++;
        else if (str[i] == '5') freq[5]++;
        else if (str[i] == '6') freq[6]++;
        else if (str[i] == '7') freq[7]++;
        else if (str[i] == '8') freq[8]++;
        else if (str[i] == '9') freq[9]++;
    }

    for (i = 0; i < 10; i++){
        printf("%d", freq[i]);
    }

    printf("\n");
    return 0;
}