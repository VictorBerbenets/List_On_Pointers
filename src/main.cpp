#include "..//includes//list.h"


int main() {

    List list = ListCreate();
    int size  = 5;

    ListInsertHead(&list, 1000);

    for (int i = 0; i < size; i++) {
        ListInsertLeft(&list, i, 1);
    }

    for (int i = 0; i < size; i++) {
        ListInsertRight(&list, i*5, 5);
    }

    for (int i = 0; i < size; i++) {
        ListInsertTail(&list, i*10);
    }

    for (int i = 0; i < size; i++) {
        ListInsertHead(&list, i*15);
    }
    ListDump(list);

    int q = list.size;
    for (int i = 0; i < q; i++) {
        DeleteNode(&list, 1);
    }

    ListDump(list);
    ListDestructor(&list);

    return 0;
}