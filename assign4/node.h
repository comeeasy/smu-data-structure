// header of int key node

#ifndef __NODE_H__
#define __NODE_H__

#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct _node {
    element data;
    struct _node* link;
} Node;

Node* make_node(element data);
void delete_node(Node* del_node);
void print_node(Node* pr_node);


#endif 