#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    // Masukkan kode program disini

    if (el == 0) {
        // Masukkan kode program disini
        
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        // Masukkan kode program disini
        infotype val;
        scanf("%d", &val);
    	InsVFirst(&fibonacci,val);
        PrintInfo(fibonacci);
        return 0;
    } else {
        // Masukkan kode program disini
        infotype val1, val2;
        scanf("%d", &val1);  
        scanf("%d", &val2);   
        address p,prec = Nil;
        InsVLast(&fibonacci,val1);
        InsVLast(&fibonacci,val2);

        prec = First(fibonacci);
        p = Next(prec);
        for(int i = 0; i < (el-2); i++){
        	infotype val = prec->info + p->info;

        	InsVLast(&fibonacci, val);
        	prec = p;
        	p = Next(p);
        }
        PrintInfo(fibonacci);
    }

    return 0;
}
// List fibonacci adalah list yang elemennya merupakan jumlah dari 2 elemen sebelumnya. Pada awal program, program akan meminta jumlah elemen dari list fibonaci yang akan dibuat. Selanjutnya, program akan mengeluarkan output sesuai aturan berikut:

//     Apabila jumlah elemen = 0, maka program akan langsung mengembalikan list kosong.
//     Apabila jumlah elemen = 1, maka program akan meminta sebuah inputan yang menjadi elemen dalam list
//     Apabila jumlah elemen >=2, maka program akan meminta dua buah inputan. Inputan pertama adalah elemen pertama dalam list dan inputan kedua adalah elemen kedua dalam list