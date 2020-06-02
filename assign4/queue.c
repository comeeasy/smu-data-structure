#include "list.h"

typedef struct _queue {
    Node* front;
    Node* rear;
    int n;  
} Queue;

Queue* init_queue(Queue* q) {
    q = (Queue*)malloc(sizeof(Queue));

    q->front = NULL;
    q->rear = NULL;
    q->n = 0;

    return q;
}

