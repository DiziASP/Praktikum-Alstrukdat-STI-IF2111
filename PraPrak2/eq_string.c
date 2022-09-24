#include <stdio.h>

int main()
{
    char firstString[100], secondString[100];
    
    scanf("%s %s", firstString, secondString);
    
    int firstLength, secondLength;
    
    for (firstLength = 0; firstLength < 100; firstLength++){
        if (firstString[firstLength] == '\0'){
            break;
        }
    }
    
    for (secondLength = 0; secondLength < 100; secondLength++){
        if (secondString[secondLength] == '\0'){
            break;
        }
    }
    
    if (firstLength != secondLength){
        printf("Tidak\n");
        return 0;
    }
    
    int i = 0;
    
    for (i = 0; i < firstLength; i++){

        int diff = firstString[i] - secondString[i];
        
        if (diff < 0){
            diff *= -1;
        }
        
        if (diff != 0 && diff != 32){
            printf("Tidak\n");
            return 0;
        }
    }
    
    printf("Ya\n");
    return 0;
}
