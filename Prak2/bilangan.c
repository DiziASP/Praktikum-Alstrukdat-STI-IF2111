#include <stdio.h>
#include <stdbool.h>

bool containSev(int x)
{
    while (x > 0)
    {
        if (x % 10 == 7)
            break;
 
        x = x / 10;
    }
 
    return (x > 0);
}

int main(){
    int N;
    scanf("%d", &N);
    
    int i,j;
    
    for (i = 1; i <= N; i++){
        int M;
        scanf("%d", &M);

        long int sum = 0;
        for (j = 1; j <= M; j++){
            if (containSev(j)==true || j % 7 == 0){
                sum += j;
            }
        }
        printf("%ld\n", sum);
    }
    return 0;
}