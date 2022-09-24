#include<stdio.h>  

int main(){    
    int n,total=0,rem;    
      
    scanf("%d",&n);    

    while(n > 0){    
        rem = n%10;    
        total = total+rem;    
        n = n/10;    
    } 

    printf("%d\n",total);    
    return 0;  
}   