#include "list.h"

List* init_list(List* list) {
    list = (List*)malloc(sizeof(List));

    list->head = NULL;
    list->n = 0;

    return list;
}

void print_list(List* list) {
    Node* tmp = list->head;

    printf("---- List ------------------------------------------------\n");
    for(int i=0; i<list->n-1; ++i) {
        print_node(tmp);
        tmp = tmp->link;
    }
    printf("\n");
    printf("----------------------------------------------------------\n");

}

void delete_list(List* del_list) {
    for(int i=0; i<del_list->n; ++i) {
        delete_node(del_list->head);
        del_list->head = del_list->head->link;
    }
}

List* insert_first(List* list, Node* new_node) {
    if(list->head == NULL) {
        list->head = new_node;
    }
    else {
        new_node->link = list->head;
        list->head = new_node;
    }
    list->n++;

    return list;
}

List* delete_first(List* list) {
    Node* tmp = list->head;
    
    if(list->n == 0) return NULL;
    else {
        list->head = list->head->link;
        delete_node(tmp);
        list->n--;
    }
    
    return list;
}

List* insert_last(List* list, Node* new_node) {
    Node* tmp = list->head;

    for(int i=0; i<list->n-1; ++i) tmp = tmp->link;
    tmp->link = new_node;
    list->n++;

    return list;
}

List* delete_last(List* list) {
    Node* tmp = list->head;

    if(list->n == 0) return NULL;
    else {
        for(int i=0; i<list->n-2; ++i) tmp = tmp->link;
        delete_node(tmp->link);
        tmp->link = NULL;
        list->n--;

        return list;
    }
}

Node* get_last_node(List* list) {
    Node* tmp = list->head;

    for(int i=0; i<list->n-1; ++i)
        tmp = tmp->link;

    return tmp;
}
