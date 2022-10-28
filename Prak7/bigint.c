#include "stack.h"
#include <math.h>
#include <stdio.h>

Stack StrToStack(Stack *s, char *val)
{
    char *cc = val;
    while (*cc != '\0')
    {
        Push(s, *cc - '0');
        cc++;
    }
}

int getStrLen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
void subtract(Stack s1, Stack s2, Stack *ans)
{
    while (!IsEmpty(s1) || !IsEmpty(s2))
    {
        infotype top1, top2;

        if (!IsEmpty(s2))
        {
            Pop(&s1, &top1);
            Pop(&s2, &top2);

            if (top1 < top2)
            {
                top1 += 10;
                infotype currTop;
                Pop(&s1, &currTop);
                currTop--;
                Push(&s1, currTop);
            }
            Push(ans, top1 - top2);
        }
        else
        {
            Push(ans, InfoTop(s1));
            Pop(&s1, &top1);
        }
    }
}

void printStack(Stack s)
{
    infotype top;
    while (!IsEmpty(s))
    {
        Pop(&s, &top);
        printf("%d", top);
    }
    printf("\n");
}

int checkGreater(char *val1, char *val2)
{
    int lenS1 = getStrLen(val1);
    int lenS2 = getStrLen(val2);

    if (lenS1 > lenS2)
    {
        return 1;
    }
    else if (lenS1 < lenS2)
    {
        return -1;
    }
    else
    {
        int i = 0;
        while (i < lenS1)
        {
            if (val1[i] > val2[i])
            {
                return 1;
            }
            else if (val1[i] < val2[i])
            {
                return -1;
            }
            i++;
        }
        return 1;
    }
}

void removeTrailingZero(Stack *s)
{
    infotype dump;
    while (!IsEmpty(*s))
    {
        if (InfoTop(*s) == 0)
        {
            Pop(s, &dump);
        }
        else
            break;
    }
    if (IsEmpty(*s))
    {
        Push(s, 0);
    }
}

int main()
{
    char s1[100], s2[100];

    scanf("%s", s1);
    scanf("%s", s2);

    Stack s1Stack, s2Stack, ans;
    CreateEmpty(&s1Stack);
    CreateEmpty(&s2Stack);
    CreateEmpty(&ans);

    StrToStack(&s1Stack, s1);
    StrToStack(&s2Stack, s2);

    int greater = checkGreater(s1, s2);

    if (greater == 1)
    {
        subtract(s1Stack, s2Stack, &ans);
    }
    else if (greater == -1)
    {
        printf("-");
        subtract(s2Stack, s1Stack, &ans);
    }
    removeTrailingZero(&ans);
    printStack(ans);
    return 0;
}