#include "reverse.h"

void transferReverse(Queue *q1, Queue *q2)
{

    int initHead = q1->HEAD, initTail = q1->TAIL;

    int length = Length(*q1);
    q2->TAIL = q1->TAIL - 1;
    for (int i = 0; i < length; i++)
    {
        Push(q2, Pop(q1));
        q2->TAIL -= 2;
    }
    q2->TAIL = initTail;
    q2->HEAD = initHead;
}