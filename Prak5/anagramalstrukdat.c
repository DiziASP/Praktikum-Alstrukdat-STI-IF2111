#include "anagramalstrukdat.h"

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char *command)
{
    Word res;
    res.Length = stringLength(command);
    for (int i = 0; i < res.Length; i++)
    {
        res.TabWord[i] = command[i];
    }
    return res;
}

int Count(char C, Word K)
{
    int i;
    int count = 0;
    for (i = 0; i < K.Length; i++)
    {
        if (K.TabWord[i] == C)
        {
            count++;
        }
    }
    return count;
}
/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2)
{
    if (string1.Length != string2.Length)
    {
        return false;
    }
    else
    {
        int i = 0;
        boolean found = false;
        while (i < string1.Length && !found)
        {
            if (Count(string1.TabWord[i], string1) != Count(string2.TabWord[i], string2))
            {
                i++;
            }
            else
            {
                found = true;
            }
        }
        return found;
    }
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat
    pada argumen frek */
void anagramalstrukdat(int *frek)
{
    *frek = 0;
    STARTWORD();
    while (!isEndWord())
    {
        if (isAnagram(currentWord, toKata("alstrukdat")))
        {
            (*frek)++;
        }
        ADVWORD();
    }
}