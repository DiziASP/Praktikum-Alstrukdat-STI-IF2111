#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url)
{
    CreateEmpty(history);
    Push(openedTab, url);
}
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */

char *currentUrl(Stack *openedTab)
{
    return InfoTop(*openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */

char *browserHistoryBack(Stack *openedTab, Stack *history, int steps)
{
    char *url;
    int i;
    for (i = 0; i < steps; i++)
    {
        Pop(openedTab, &url);
        Push(history, url);
    }
    return InfoTop(*openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps)
{
    char *url;
    int i;
    for (i = 0; i < steps; i++)
    {
        Pop(history, &url);
        Push(openedTab, url);
    }
    return InfoTop(*openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */

void browserHistoryFree(Stack *history)
{
    CreateEmpty(history);
}
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */