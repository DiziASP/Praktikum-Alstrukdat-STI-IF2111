#include "mesinkata.h"

/* *** Definisi Variabel Mesin *** */
char currentChar; // Character Machine
boolean EOP;
Word currentWord; // Word Machine
boolean EndWord;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void ADVWORD()
{
    IgnoreBlanks();
    if (EOP && EndWord == false)
    {
        EndWord = true;
    }

    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWord()
{
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && i < NMax)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}
