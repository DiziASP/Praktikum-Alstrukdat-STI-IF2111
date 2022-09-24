#include "jumlahkonsonanvokal.h"
#include <stdio.h>
#include <ctype.h>

// Parameter pertama merupakan kalimat
// Parameter kedua merupakan jumlah huruf konsonan
// Parameter ketiga merupakan jumlah huruf vokal

void jumlahKonsonanVokal(char* str, int* konso, int* voc){
    int i = 0;
    while (str[i] != '\0'){
        
        if(str[i] == 'A' || str[i] == 'a' ||
           str[i] == 'I' || str[i] == 'i' ||
           str[i] == 'U' || str[i] == 'u' ||
           str[i] == 'E' || str[i] == 'e' ||
           str[i] == 'O' || str[i] == 'o'){
            (*voc)++;
            }
        else{
            if(isalpha(str[i])){
                (*konso)++;
            }
        }
        i++;
    }
}
