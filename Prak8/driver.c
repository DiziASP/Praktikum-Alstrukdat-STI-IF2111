#include "union_map.h"
#include "map.h"
int main()
{
    Map m1, m2, m3;
    CreateEmpty(&m1);
    CreateEmpty(&m2);

    Insert(&m1, 7, 1);
    Insert(&m1, 1, 2);
    Insert(&m1, 20, 3);

    Insert(&m2, 8, 100);
    Insert(&m2, 11, 10);

    m3 = UnionMap(m1, m2, true);

    for (int i = 0; i < m3.Count; i++)
    {
        printf("%d:%d ", m3.Elements[i].Key, m3.Elements[i].Value);
    }

    printf("\n");

    return 0;
}