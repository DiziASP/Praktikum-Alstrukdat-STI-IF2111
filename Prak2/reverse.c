#include <stdio.h>

int main(){
    long int inp;

    scanf("%ld", &inp);
    int rem = 0, rev = 0;
    while (inp != 0)
    {
        rem =  inp % 10;
        rev = rev * 10 + rem;
        inp /= 10;
    }
    
    printf("%d\n", rev);
    return 0;
}