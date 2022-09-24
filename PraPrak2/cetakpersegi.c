#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    
    if (n <= 0){
        return 0;
    }
    
    int param = 2 * n - 1;
    
    int i;
    for (i = 1; i < param * param + 1; i++){
        if (i % 2 != 0){
            printf("O");
        } else {
            printf("X");            
        }
        
        if (i % param == 0){
            printf("\n");
        }
    }
    return 0;
}