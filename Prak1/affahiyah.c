#include <stdio.h>

int main(){
    long int x;
    scanf("%ld", &x);

    if (x % 2 == 0 && x != 2) printf("Ya\n");
    else printf("Tidak\n");
}