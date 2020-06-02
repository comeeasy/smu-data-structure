#include "list.h"

typedef struct _stack {
    Node* top;
    int n;
} Stack;

Stack* init_stack(Stack* s) {
    s = (Stack*)malloc(sizeof(Stack));

    s->top = NULL;
    s->n = 0;

    return s;
}

void push(Stack* stack, element data) {
    insert_list((List*)stack, make_node(data));
}

element pop(Stack* stack) {
    Node* tmp = stack->top;
    element elem;

    if(stack->n > 0) {
        for(int i=0; i<stack->n-1; ++i) 
            tmp = tmp->link;
            elem = tmp->data;
            delete_node(tmp);
            return elem;
    }
    else {
        printf("---- Stack is empty! ------\n");
    }
}

