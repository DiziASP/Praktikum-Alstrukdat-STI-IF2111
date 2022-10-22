#include "stack.h"
#include <stdio.h>

boolean isPalindrome(Stack boi)
{
    Stack temp, temp2;
    CreateEmpty(&temp);
    temp2 = boi;
    while (!IsEmpty(temp2))
    {
        infotype val;
        Pop(&temp2, &val);
        Push(&temp, val);
    }
    while (!IsEmpty(temp))
    {
        infotype temp1, temp2;
        Pop(&temp, &temp1);
        Pop(&boi, &temp2);
        if (temp1 != temp2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Stack inputStack;
    CreateEmpty(&inputStack);

    int inp;
    scanf("%d", &inp);
    while (inp != 0 && !IsFull(inputStack))
    {
        Push(&inputStack, inp);
        scanf("%d", &inp);
    }

    if (IsEmpty(inputStack))
    {
        printf("Stack kosong\n");
    }
    else
    {
        printf(isPalindrome(inputStack) ? "Palindrom\n" : "Bukan Palindrom\n");
    }
    return 0;
}