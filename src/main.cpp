#include "..//includes//list.h"


int main() {


    // list.head = (Node*) calloc(1, sizeof(Node));

    List list = ListCreate();
    ListInsertTail(&list, 0);
    ListInsertTail(&list, 1);
    ListInsertTail(&list, 2);
    ListInsertTail(&list, 3);
    // ListInsertHead(&list, 4);
    // ListInsertHead(&list, 5);

    ListInsertLeft(&list, 1491, 1);
    ListInsertRight(&list, 1488, 3);
    ListInsertLeft(&list, 1489, 3);
    ListInsertLeft(&list, 1490, 3);
    ListInsertRight(&list, 1492, 3);
    ListInsertRight(&list, 1493, 3);
    ListInsertRight(&list, 1494, 3);
    ListDump(&list);
    int q = list.size;
    for (int i = 0; i < q; i++) {
        printf("i = %d\n", i);
    ListDump(&list);

        DeleteNode(&list, 1);
    }


    ListDump(&list);

    ListDestructor(&list);

    return 0;
}