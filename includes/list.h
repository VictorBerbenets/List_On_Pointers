#ifndef LISTIK_H
#define LISTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validator.h"
#include "colors.h"

typedef double elem_t;
const int Max_Dot_Command_Len = 150;

/// list structers///
typedef struct {

    elem_t value;
    Node* next;
    Node* prev;

} Node;

typedef struct {

    Node* tail;
    Node* head;
    int size;
} List;
/////////////////////

enum List_params {

    ListInitSize  = 0,
    One_Node      = 1,
};

enum ListErrors {

    MEM_ALLOCATED_ERR   = 5353535, 
    INVALID_LOGIC_ID    = -101,
    INVALID_NODE_ID     = 100,
    CLOSE_FILE_ERROR    = 0XDEADFEED,
    OPEN_FILE_ERROR     = 0XDEADBABE,
} ;

#endif

List ListCreate();

int ListInsertTail(List* list, elem_t value);

int ListInsertHead(List* list, elem_t value);

int ListInsertRight(List* list, elem_t value, int logic_id);

int ListInsertLeft(List* list, elem_t value, int logic_id);

void InsertFromTail(List* list, elem_t value, int logic_id);

void InsertFromLeft(List* list, elem_t value, int logic_id);

int FindFirstListValue(List* list, elem_t value);

int DeleteNode(List* list, int logic_id);

void ListDestructor(List* list);

void ListDump(List* list);