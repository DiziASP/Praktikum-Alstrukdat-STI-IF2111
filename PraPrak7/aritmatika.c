#include "aritmatika.h"

boolean isOperator(char input)
{
    return (input == '+' || input == '-' || input == '*' || input == '/');
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op)
{
    switch (op)
    {
    case '+':
        return angka1 + angka2;
    case '-':
        return angka1 - angka2;
    case '*':
        return angka1 * angka2;
    case '/':
        return angka1 / angka2;
    default:
        return 0;
    }
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length)
{
    Stack operand;
    CreateEmpty(&operand);
    for (int i = 0; i < length; i++)
    {
        if (isOperator(input[i]))
        {
            infotype operand1, operand2;
            Pop(&operand, &operand1);
            Pop(&operand, &operand2);
            Push(&operand, hitung(operand2, operand1, input[i]));
        }
        else
        {
            Push(&operand, input[i] - '0');
        }
    }
    infotype res;
    Pop(&operand, &res);
    return res;
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
