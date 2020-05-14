// circular priority queue 구현
// array로 구현할 것, 기존의 queue에 더하여 구현할 것
/*
    과제1. 우선순위 원형 큐 구현
- 구조체로 큐 선언(형식 상관 없음, 단, 우선순위는 포함할 것)
- 큐 함수는 교수님이 주신거에서 변형
- 큐에 변수와 우선순위 무작위로 넣었을 때 우선순위 낮은 변수 
  먼저 dequeue 되게 할 것
- 위 작업 여러번 반복해도 문제 없도록 할 것
- 정렬 작업은 아무거나 써도 되나 가장 효율적인 것으로 해볼 것

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

#define MAX_QUEUE 10
////////////////////////////////////////////////////////////////////////////////////////
typedef struct _element {
    int key;
    int priority;
} Element;

typedef struct _queue {
    Element data[MAX_QUEUE];
    int front, rear;
} Queue;
////////////////////////////////////////////////////////////////////////////////////////
// insertion 방식으로 구현할 거임
Queue* init_queue(Queue* q) {
    q = (Queue*)malloc(sizeof(Queue)*MAX_QUEUE);
    q->front = 0;
    q->rear  = 0;
}
void delete_queue(Queue* q) {free(q);}
int is_empty(Queue* q) {return (q->rear == q->front ? 1 : 0);}
int is_full(Queue* q) {
    if((q->rear + MAX_QUEUE)%MAX_QUEUE == (q->front + MAX_QUEUE - 1)%MAX_QUEUE ) {
        return 1;
    }
    else {
    
    } 
        return 0;
}
void print_queue(Queue* q) {
    int start, end;

    printf("\n------------ Queue ----------------------\n");

    for(int i=0; i<MAX_QUEUE; ++i) printf("%3d", i);
    printf("\n");

    if(q->rear > q->front) {
        for(int i=0; i<MAX_QUEUE; ++i) {
            if(i == q->front)       printf("  f");
            else if(i == q->rear)   printf("  r");
            else                    printf("   ");
        }
        printf("\n");
        for(int i=0; i<MAX_QUEUE; ++i) {
            if(i >= (q->front+MAX_QUEUE)%MAX_QUEUE && i < (q->rear+MAX_QUEUE)%MAX_QUEUE) {
                printf("%3d", (q->data[i]).key);
            }
            else {
                printf("   ");
            }
        } 
    }
    else if(q->rear < q->front) {
        for(int i=0; i<MAX_QUEUE; ++i) {
            if(i == q->front)       printf("  f");
            else if(i == q->rear)   printf("  r");
            else                    printf("   ");
        }
        printf("\n");
        for(int i=0; i<MAX_QUEUE; ++i) {
            if(i >= (q->front+MAX_QUEUE)%MAX_QUEUE || i < (q->rear+MAX_QUEUE)%MAX_QUEUE) {
                printf("%3d", (q->data[i]).key);
            }
            else {
                printf("   ");
            }
        } 
    }
    else {
        for(int i=0; i<MAX_QUEUE; ++i) {
            if(i == q->front)       printf("  f");
            else if(i == q->rear)   printf("  r");
            else                    printf("   ");
        }
        printf("\n   EMPTY\n");        
    }

    printf("\n-----------------------------------------\n");

}

void enqueue(Queue* q, Element elem) {
    Element tmp1=elem, tmp2;

    if(!is_full(q)) {
        // 일반 circular queue
        //q->data[q->rear++] = elem;
        //if(q->rear == MAX_QUEUE) q->rear %= MAX_QUEUE;

        //priority-queue
        if(is_empty(q)) {
            q->data[q->rear++] = elem;
        }
        else {
            for(int i=q->front; i!=q->rear; i=(i+1)%MAX_QUEUE) {
                tmp2 = q->data[i];
                if(tmp1.priority < tmp2.priority) {
                    q->data[i] = tmp1;
                    tmp1 = tmp2;
                }
            }
            q->data[q->rear] = tmp1;
            q->rear++;
        }

        if(q->rear == MAX_QUEUE) q->rear %= MAX_QUEUE;
    }   
    else {
        printf("Queue is full!\n");
    }
    //print_queue(q);
} 

Element dequeue(Queue* q) {
    Element tmp;
    tmp.key = -1;
    tmp.priority = -1;

    if(!is_empty(q)) {
        tmp = q->data[q->front];
        q->front = ((q->front)+1) % MAX_QUEUE;
    }
    else {
        printf("Queue is empty!\n");
    }

    print_queue(q);

    return tmp;
}
////////////////////////////////////////////////////////////////////////////////////////
Element make_elem(int key, int priority) {
    Element tmp;

    tmp.key = key;
    tmp.priority = priority;

    return tmp;
}
////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int n, key, priority;
    Queue* q;

    q = init_queue(q);

    printf("How many variables will you insert? : ");
    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        printf("Enter your Variable and the Priority of the Variable #%d: ", i);
        scanf("%d %d", &key, &priority);
        printf("entered %d %d\n", key, priority);
        enqueue(q, make_elem(key, priority));
    }

    printf("The list under is the queue you've entered if it is correct press enter to continue\n");
    print_queue(q);

    delete_queue(q);
    return 0;
}