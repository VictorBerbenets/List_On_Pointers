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

    new_head->next   = list->head;
    list->head->prev = new_head;

    list->head = new_head;
    list->head->value = value;
    list->head->prev  = nullptr;

    list->size++;
}

int ListInsertRight(List* list, elem_t value, int logic_id) {

    if (logic_id == list->size) {
        ListInsertTail(list, value);
        return INSERT_TAIL;
    }
    if (logic_id < 1 || logic_id > list->size) {
        fprintf(stderr, "invalid logic id: %d\n", logic_id);
        return INVALID_LOGIC_ID;
    }

    InsertNode(list, value, logic_id);
}

// This func inserts new node only with ride side of the logic node
void InsertNode(List* list, elem_t value, int logic_id) {

    Node* curr_node_ptr = GetIdByOptimalWay(list, logic_id);
    Node* next_node     = curr_node_ptr->next;

    Node* new_node = (Node*) calloc(One_Node, sizeof(Node));
    Validator(new_node == nullptr, in calloc: could not give memory);

    new_node->next  = next_node;
    new_node->prev  = curr_node_ptr;
    next_node->prev = new_node;
    curr_node_ptr->next = new_node;
    new_node->value     = value;

    list->size++;
}

int ListInsertLeft(List* list, elem_t value, int logic_id) {

    if (logic_id == (ListInitSize + 1)) {
        ListInsertHead(list, value);
        return INSERT_HEAD;
    }

    if (logic_id < 1 || logic_id > list->size) {
        fprintf(stderr, "invalid logic id: %d\n", logic_id);
        return INVALID_LOGIC_ID;
    }

    InsertNode(list, value, logic_id - 1);
}

int DeleteNode(List* list, int logic_id) {
    printf("logic id = %d\n", logic_id);
    if (logic_id < 1 || logic_id > list->size) {
        fprintf(stderr, "invalid logic id: %d\n", logic_id);
        return INVALID_LOGIC_ID;
    }
    if (logic_id == list->size) {
        DeleteTail(list);
        return 0;
    }
    if (logic_id == (ListInitSize + 1)) {
        DeleteHead(list);
        return 0;
    }
    Node* node_to_del = GetIdByOptimalWay(list, logic_id);
    // Node* left_neighbour  = node_to_del->prev;
    // Node* right_neighbour = node_to_del->next;
    fprintf(stderr, "line = %d\n", __LINE__);
    // left_neighbour->next  = right_neighbour;
    // right_neighbour->prev = left_neighbour;
    // printf("not to del = %p\n", node_to_del);
    // fprintf(stderr, "line = %d\n", __LINE__);

    fprintf(stderr, "not to del value  = %lg\n", node_to_del->value);
    // fprintf(stderr, "line = %d\n", __LINE__);

    // printf("not to del value next  = %p\n", node_to_del->next);
    // fprintf(stderr, "line = %d\n", __LINE__);

    // printf("not to del value prev  = %p\n", node_to_del->prev);
    // fprintf(stderr, "line = %d\n", __LINE__);
    node_to_del->prev->next = node_to_del->next;
    node_to_del->next->prev = node_to_del->prev;

    free(node_to_del);
    list->size--;
}

void DeleteTail(List* list) {

    Node* left_neighbour = list->tail->prev;
    left_neighbour->next = nullptr;
    free(list->tail);
    list->tail = left_neighbour;
    list->size--;
}

void DeleteHead(List* list) {

    Node* right_neighbour = list->head->next;
    right_neighbour->prev = nullptr;
    free(list->head);
    list->head = right_neighbour;
    list->size--;
}
Node* GetIdByOptimalWay(List* list, int logic_id) {

    int path_length = 0;
    Node* curr_node_ptr = nullptr;
    printf("list size = %d\n", list->size);
    if (logic_id >= list->size/2) {   
        path_length   = list->size - logic_id; 
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

    return curr_node_ptr;
}
int FindFirstListValue(List* list, elem_t value) {

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