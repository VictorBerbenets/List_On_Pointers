#include "..//includes//list.h"

List ListCreate() {

    List list = {};
    list.size = 0;

    list.head = nullptr;
    list.tail = nullptr;

    return list;
}

int ListInsertTail(List* list, elem_t value) {
    
    Node* new_tail = (Node*) calloc(One_Node, sizeof(Node));
    Validator(new_tail == nullptr, in Calloc: could not give memory, return MEM_ALLOCATED_ERR);

    if (list->size == ListInitSize) {

        list->head = new_tail;
        list->head->next = nullptr;
        list->head->prev = nullptr;

        list->tail = new_tail;
        list->tail->value = value;
        list->tail->next  = nullptr;
        list->tail->prev  = nullptr;
        list->size++;

        return 0;
    }
    new_tail->prev   = list->tail;
    list->tail->next = new_tail;

    list->tail = new_tail;
    list->tail->value = value;
    list->tail->next  = nullptr;

    list->size++;
}

int ListInsertHead(List* list, elem_t value) {
    fprintf(stderr, "Line = %d\n", __LINE__);

    Node* new_head = (Node*) calloc(One_Node, sizeof(Node));
    Validator(new_head == nullptr, in Calloc: could not give memory, return MEM_ALLOCATED_ERR);

    if (list->size == ListInitSize) {
        list->tail = new_head;
        list->tail->next = nullptr;
        list->tail->next = nullptr;

        list->head = new_head;
        list->head->value = value;
        list->head->next  = nullptr;
        list->head->prev  = nullptr;
        list->size++;

        return 0;
    }
    fprintf(stderr, "Line = %d\n", __LINE__);

    new_head->next   = list->head;
    fprintf(stderr, "Line = %d\n", __LINE__);
    list->head->prev = new_head;
    fprintf(stderr, "Line = %d\n", __LINE__);

    list->head = new_head;
    list->head->value = value;
    list->head->prev  = nullptr;
    fprintf(stderr, "Line = %d\n", __LINE__);

    list->size++;
}

int ListInsertRight(List* list, elem_t value, int logic_id) {

    if (logic_id < 1 || logic_id > list->size) {
        fprintf(stderr, "invalid logic id: %d\n", logic_id);
        return INVALID_LOGIC_ID;
    }

    if (logic_id == list->size) {
        ListInsertTail(list, value);
    }

    // if (logic_id >= list->size/2) {
    //     InsertFromTail(list, value, logic_id);
    // }
    // else {
    //     InsertFromHead(list, value, logic_id);
    // }

}

int ListInsertLeft(List* list, elem_t value, int logic_id) {

    if (logic_id < 1 || logic_id > list->size) {
        fprintf(stderr, "invalid logic id: %d\n", logic_id);
        return INVALID_LOGIC_ID;
    }

    if (logic_id == (ListInitSize + 1)) {
        ListInsertHead(list, value);
    }

}

void InsertFromTail(List* list, elem_t value, int logic_id) {

    int path_length     = 0;
    Node* curr_node_ptr = nullptr;

    if (logic_id >= list->size/2) {   
        path_length     = list->size - logic_id; 
        curr_node_ptr = list->tail;
        for (int node_counter = 0; node_counter < path_length; node_counter++) {
            curr_node_ptr = curr_node_ptr->prev;
        }
    }
    else {
        path_length   = logic_id;
        curr_node_ptr = list->head;
        for (int node_counter = 0; node_counter < path_length; node_counter++) {
            curr_node_ptr = curr_node_ptr->next;
        }
    }

    Node* next_node = curr_node_ptr->next;

    Node* new_node = (Node*) calloc(One_Node, sizeof(Node));
    Validator(new_node == nullptr, in calloc: could not give memory);

    new_node->next  = curr_node_ptr->next;
    new_node->prev  = curr_node_ptr;
    next_node->prev = new_node;
    curr_node_ptr->next = new_node;

    new_node->value = value;

    list->size++;
}

void InsertFromHead(List* list, elem_t value, int logic_id) {

}

int FindFirstListValue(List* list, elem_t value) {

}

int DeleteNode(List* list, int logic_id) {

}

void ListDestructor(List* list) {

    Node* curr_ptr = list->head;
    Node* next_node_ptr = nullptr;
    while(curr_ptr != nullptr) {

        curr_ptr->value = Poison;
        next_node_ptr = curr_ptr->next;
        free (curr_ptr);
        curr_ptr = next_node_ptr;
    }
}

void ListDump(List* list) {
    
    Node* curr_ptr = list->head;
    printf("From Head to Tail:\n");
    for (int i = 1; i <= list->size && curr_ptr != nullptr; i++, curr_ptr = curr_ptr->next) {
        printf("[%d] = %lg\n", i, curr_ptr->value);
    }

    curr_ptr = list->tail;
    printf("\n\nFrom Tail to Head:\n");
    for (int i = 1; i <= list->size && curr_ptr != nullptr; i++, curr_ptr = curr_ptr->prev) {
        printf("[%d] = %lg\n", i, curr_ptr->value);
    }
}