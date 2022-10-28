#include "valid.h"

Stack validParantheses(char *input, int length)
{
    Stack S, res;
    CreateEmpty(&S);
    CreateEmpty(&res);
    int i;
    char temp;
    for (i = 0; i < length; i++)
    {
        if (IsEmpty(S))
        {
            Push(&S, input[i]);
        }
        else if (input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            Push(&S, input[i]);
        }
        else if (input[i] == ')' && InfoTop(S) == '(')
        {
            Push(&res, InfoTop(S));
            Push(&res, input[i]);
            Pop(&S, &input[i]);
        }
        else if (input[i] == ']' && InfoTop(S) == '[')
        {
            Push(&res, InfoTop(S));
            Push(&res, input[i]);
            Pop(&S, &input[i]);
        }
        else if (input[i] == '}' && InfoTop(S) == '{')
        {
            Push(&res, InfoTop(S));
            Push(&res, input[i]);
            Pop(&S, &input[i]);
        }
        else
        {
            Push(&S, input[i]);
        }
    }
    return res;
}
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/