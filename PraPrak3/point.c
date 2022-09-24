#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* ***Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut*** */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float x,y;
    scanf("%f %f",&x,&y);
    *P = MakePOINT(x,y);

}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */     
    printf("(%.2f,%.2f)",P.X,P.Y);
}
             

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (P1.X == P2.X) && (P1.Y == P2.Y);
}

boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (P1.X != P2.X) || (P1.Y != P2.Y);
}



/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    return (P.X == 0 && P.Y == 0);
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return (P.Y == 0);
}

boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu Y */
    return (P.X == 0);
}

int Kuadran (POINT P){
    /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
    /* Prekondisi : P bukan titik origin, 
                    dan P tidak terletak di salah satu sumbu */
    if (IsOrigin(P) == false && IsOnSbX(P) == false && IsOnSbY(P)== false) {
        if(P.X > 0  && P.Y > 0){
            return 1;
        }
        else if(P.X < 0  && P.Y > 0){
            return 2;
        }
        else if(P.X < 0  && P.Y < 0){
            return 3;
        }
        else if(P.X > 0  && P.Y < 0){
            return 4;
        }
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    POINT P1;
    P1.X = P.X + deltaX;
    P1.Y = P.Y + deltaY;
    return P1;
}


void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    P->X = P->X + deltaX;
    P->Y = P->Y + deltaY;
}

float Jarak0 (POINT P){
    /* Menghitung jarak P ke (0,0) */
    return sqrt(P.X*P.X + P.Y*P.Y);
}

float Panjang (POINT P1, POINT P2){
    /* Menghitung panjang garis yang dibentuk P1 dan P2 */
    return sqrt(pow((P1.X-P2.X),2) + pow((P1.Y-P2.Y),2));
}

