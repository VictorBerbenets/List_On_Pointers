#include "..//includes//list.h"


int main() {


    // list.head = (Node*) calloc(1, sizeof(Node));

    List list = ListCreate();
    ListInsertTail(&list, 0);
    ListInsertTail(&list, 0);
    ListInsertTail(&list, 0);
    ListInsertTail(&list, 0);
    ListInsertHead(&list, 0);
    ListInsertHead(&list, 0);

    


    ListDump(&list);



     ListDestructor(&list);

    return 0;
}