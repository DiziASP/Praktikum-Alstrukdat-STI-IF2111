#include <stdio.h>
#include "mesinkarakter.h"

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

char currentChar;
boolean EOP;

void START()
{
    currentChar = getchar();
    EOP = IsEOP();
}

/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
void ADV()
{
    currentChar = getchar();
    EOP = IsEOP();
}

/* Mengirimkan currentChar */
char GetCC()
{
    return currentChar;
}

/* Mengirimkan true jika currentChar = MARK */
boolean IsEOP()
{

    return currentChar == MARK;
}