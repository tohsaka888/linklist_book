#include <stdio.h>
#include "book.h"

int main() {
    linklist *L;
    InitList(&L);
    CreateList(&L);
    DeleteBook(&L,2);
    InsertBook(&L,2);
    ShowList(&L);
    return 0;
}
