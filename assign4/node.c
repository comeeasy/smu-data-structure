#include "node.h"

Node* make_node(element data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    new_node->link = NULL;
    
    return new_node;
}

void delete_node(Node* del_node) {free(del_node);}
void print_node(Node* pr_node) {printf("%d->", pr_node->data);}

