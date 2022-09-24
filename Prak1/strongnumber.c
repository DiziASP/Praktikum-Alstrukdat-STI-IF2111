#include <stdio.h>

int fact(int x){
    if (x == 0) return 1;
    return x * fact(x - 1);
}

int main()
{
    int x;
    scanf("%d", &x);

    int temp = x, rem, sum = 0;
    while (temp != 0)
    {
        rem = temp % 10;
        sum += fact(rem);
        temp /= 10;
    }
    
    printf(sum == x ? "Y\n" : "N\n");
}