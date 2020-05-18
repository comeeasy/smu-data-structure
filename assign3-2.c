/*
과제2. enqueue와 dequeue 활용
- 원형 큐에 1234 입력 시 
1. 1234
2. 234
3. 342
4. 42
5. 24
6. 4
다음 단계 거쳐서 큐에 변수 하나 남을 때 남은 변수 dequeue 및 화면에 출력
https://www.acmicpc.net/problem/2164 참고
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100

typedef int element;
typedef struct _queue {
    element* data;
    int size;
    int front, rear;
} Queue;

Queue* create(Queue* q, int size) {
    if(size > 100) {
        printf("size is limited under 100\n");
        return NULL;
    }

    q = (Queue*)malloc(sizeof(Queue));
    q->data = (element*)malloc(sizeof(element)*size);
    q->size = size;
    q->front = 0;
    q->rear = 0;

    return q;
}

void delete_queue(Queue* q) {
    free(q->data);
    free(q);
}

int size_of_queue(Queue* q) {
    return ( (q->rear)%q->size - (q->front+1)%q->size );
}
int is_full(Queue* q) {return( (q->rear+1)%(q->size) == q->front%(q->size) ? 1 : 0);}
int is_empty(Queue* q) {return( (q->rear == q->front ? 1 : 0) );}
void enqueue(Queue* q, element item) {
    if(!is_full(q)) {
        q->rear = (q->rear+1)%q->size;
        q->data[q->rear] = item;
    }
    else {
        printf("queue is full!\n");
    }
}
element dequeue(Queue* q) {
    if(!is_empty(q)) {
        return q->data[++q->front];
    }
    else return -1;
}
void print_queue(Queue* q) {
    for(int i=q->front+1; i<=q->rear; ++i) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue* q;

    q = create(q, MAX_QUEUE);
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    element feedback;
    while(size_of_queue(q) >= 2) {
        printf("Deqed %d\n", dequeue(q));
        printf("Deqed %d\n", feedback = dequeue(q));
        enqueue(q, feedback);
        print_queue(q);
    }
    printf("%d\n", q->data[q->rear]);

    delete_queue(q);
    return 0;
}


