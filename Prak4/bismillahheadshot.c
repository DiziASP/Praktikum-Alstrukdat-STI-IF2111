#include <stdio.h>

int main()
{
    int N, q, count;
    int *arr;

    scanf("%d", &N);

    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        count = 0;

        scanf("%d %d", &l, &r);
        for (int i = l; i <= r; i++)
        {
            count += arr[(i - 1) % N];
        }
        printf("%d\n", count);
    }
    return 0;
}