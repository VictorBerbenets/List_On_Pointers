#ifndef LISTIK_H
#define LISTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validator.h"
#include "colors.h"

#define PrintFuncPosition() fprintf(stderr, "%s was called from:\n" White " %s:%s:%d\n" Grey "", __PRETTY_FUNCTION__, file, func, line)
#define ListDump(list) _ListDump(&list, __FILE__, __PRETTY_FUNCTION__, __LINE__)


#define DotPrint(...) fprintf(dot_file, __VA_ARGS__);

#define DotStartGraph(file_name)         \
    const int Name_Size = 100;            \
    char file[Name_Size] = file_name;      \
    FILE* dot_file = fopen(file, "w+");     

#define DotSetRankdir(dir) fprintf(dot_file, "rankdir = %s\n", #dir);

#define DotSetGraph(fillcolor, ranksep, nodesep, style, color, penwidth) \
    fprintf(dot_file, "graph [fillcolor = %s, ranksep = %lg, nodesep = %lg, style = \"%s\", color = %s, penwidth = %lg];\n",\
    fillcolor, ranksep, nodesep, style, color, penwidth);

#define DotSetEdge(color, arrowhead, arrowsize, penwidth) \
    fprintf(dot_file, "edge [color = %s, arrowhead = %s, arrowsize = %lg, penwidth = %lg];\n", color, arrowhead, arrowsize,\
    penwidth);

#define DotSetNodeStyle(shape, style, fillcolor, fontcolor, margin) \
    fprintf(dot_file, "node [shape=%s, style=%s, fillcolor=%s, fontcolor=%s, margin = %s];\n", \
    #shape, #style, #fillcolor, #fontcolor, #margin);

#define DotSetNode(node_id, shape, style, fillcolor, label) \
    fprintf(dot_file, "node%d [shape=%s, style=%s, fillcolor=%s, label = %s];\n", \
    node_id, shape, style, fillcolor, label);

#define DotSetLinkStyle()

#define DotCreateNode()


#define DotEndGraph(file_name)                 \
    DotPrint("}")                               \
    fclose(file_name);                     

#define DotPrintGraph(file, picture_numb)                                           \
    const int dot_len = 150;                                                         \
    char dot_png[dot_len] = "";                                                       \
    sprintf(dot_png, "dot -Tpng %s -o data//graph_%d.png", file, picture_numb);        \
    system(dot_png);



typedef double elem_t;
const int Max_Dot_Command_Len = 150;

/// list structers///
typedef struct Node Node;

struct Node{

    elem_t value;
    Node* next;
    Node* prev;
} ;

typedef struct {

    Node* tail;
    Node* head;
    int size;
    int Dump_Number;
} List;
/////////////////////

enum List_params {

    Poison             = 0XDEADBABE,
    INSERT_TAIL        = 0xDEDFEED1,
    INSERT_HEAD        = 0xDEDFEED2,
    DELETE_TAIL        = 111,
    DELETE_Head        = 112,
    DELETE_LAST_NODE   = 113,
    VALUE_NOT_FOUND    = -1,
    ListInitSize       = 0,
    Logic_Head         = 1,
    One_Node           = 1,
};

enum ListErrors {

    MEM_ALLOCATED_ERR   = 5353535, 
    INVALID_LOGIC_ID    = 0XFEEDFAC1,
    INVALID_NODE_ID     = 0XFEEDFAC2,
    CLOSE_FILE_ERROR    = 0XDEADFEED,
    OPEN_FILE_ERROR     = 0XDEADBABE,
} ;

#endif

List ListCreate();

void InsertFirstNode(List* list, Node* new_node, elem_t value);

int ListInsertTail(List* list, elem_t value);

int ListInsertHead(List* list, elem_t value);

int ListInsertRight(List* list, elem_t value, int logic_id);

int ListInsertLeft(List* list, elem_t value, int logic_id);

void InsertNode(List* list, elem_t value, int logic_id);

Node* GetIdByOptimalWay(List* list, int logic_id);

elem_t GetListValue(List* list, int logic_id);

int FindFirstListValue(List* list, elem_t value);

int DeleteNode(List* list, int logic_id);

void DeleteLastNode(List* list);

void DeleteTail(List* list);

void DeleteHead(List* list);

void ListDestructor(List* list);

void ListDestructor(List* list);

void _ListDump(List* list, const char* file, const char* func, int line);

int ListGraph(List *list);