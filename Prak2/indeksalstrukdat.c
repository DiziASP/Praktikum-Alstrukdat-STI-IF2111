#include <stdio.h>

int main(){
    float inp,total = 0;

    int count = 0, passed =0;
    while(inp != -999){
        scanf("%f", &inp);
        if(inp == -999.00) break;

        if(inp < 0.0 || inp > 4.0) continue;

        total += inp;
        count++;

        if(inp >= 3.0) passed++;

    }

    if (count == 0) {
        printf("Tidak ada data\n");
        return 0;
    }

    float avg = total / count;
    printf("Jumlah mahasiswa yang lulus = %d\n", passed);
    printf("Nilai rata-rata = %.2f\n", avg);

    char ind;

    if (avg == 4.00) ind = 'A';
    else if (avg >= 3.00 && avg < 4.00) ind = 'B';
    else if (avg >= 2.00 && avg < 3.00) ind = 'C';
    else if (avg >= 1.00 && avg < 2.00) ind = 'D';
    else if (avg >= 0.00 && avg < 1.00) ind = 'E';

    printf("Indeks akhir kelas = %c\n", ind);
    return 0;
}