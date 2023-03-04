#include "list.h"

List ListCreate() {

    List list = {};

    list.size = 0;
    list.head->prev = nullptr;
    list.head->next = nullptr;
    list.head = nullptr;

    list.tail->prev = nullptr;
    list.tail->next = nullptr;
    list.tail = nullptr;

    return list;
}

int ListInsertTail(List* list, elem_t value) {
    
    Node* new_tail = (Node*) calloc(One_Node, sizeof(Node));
    Validator(new_tail == nullptr, in calloc: could not give memory, return MEM_ALLOCATED_ERR);

    if (list->size == ListInitSize) {
        list->head = new_tail;
    }
    new_tail->prev   = list->tail;
    list->tail->next = new_tail;

    list->tail = new_tail;
    list->tail->value = value;
    list->tail->next  = nullptr;

    list->size++;
}

int ListInsertHead(List* list, elem_t value) {

    Node* new_head = (Node*) calloc(One_Node, sizeof(Node));
    Validator(new_head == nullptr, in calloc: could not give memory, return MEM_ALLOCATED_ERR);

    if (list->size == ListInitSize) {
        list->tail = new_head;
    }

    new_head->next   = list->head;
    list->head->prev = new_head;

    list->head = new_head;
    list->head->value = value;
    list->head->prev  = nullptr;

    list->size++;
}

int ListInsertRight(List* list, elem_t value, int logic_id) {

    if (logic_id < 1 || logic_id > list->size) {
        fprintf(stderr, "invalid logic id: %d\n", logic_id);
        return INVALID_LOGIC_ID;
    }

    if (logic_id >= list->size/2) {
        InsertFromTail(list, value, logic_id);
    }
    else {
        InsertFromHead(list, value, logic_id);
    }

}

int ListInsertLeft(List* list, elem_t value, int logic_id) {

}

void InsertFromTail(List* list, elem_t value, int logic_id) {

}

void InsertFromHead(List* list, elem_t value, int logic_id) {

}

int FindFirstListValue(List* list, elem_t value) {

}

int DeleteNode(List* list, int logic_id) {

}

void ListDestructor(List* list) {

}

void ListDump(List* list) {
    
}