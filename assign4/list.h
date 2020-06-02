// header of List
#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

// Simple linked list
typedef struct _List {
    Node* head;
    // num of nodes
    int n;
} List;

List* init_list(List* list);
void print_list(List* list);
void delete_list(List* list);
List* insert_first(List* list, Node* new_node);
List* delete_first(List* list);
List* insert_last(List* list, Node* new_node);
List* delete_last(List* list);
Node* get_last_node(List* list);

#endif