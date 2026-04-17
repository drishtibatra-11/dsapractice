#include <stdio.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Stack functions
void push(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Queue functions
void enqueue(Queue *q, int x) {
    q->arr[++(q->rear)] = x;
}

int dequeue(Queue *q) {
    return q->arr[(q->front)++];
}

int isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}

int main() {
    int N, x;
    scanf("%d", &N);

    Queue q;
    q.front = 0;
    q.rear = -1;

    Stack s;
    s.top = -1;

    // Input queue elements
    for(int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Step 1: Move queue → stack
    while(!isQueueEmpty(&q)) {
        push(&s, dequeue(&q));
    }

    // Step 2: Move stack → queue (reversed)
    while(!isStackEmpty(&s)) {
        enqueue(&q, pop(&s));
    }

    // Print reversed queue
    while(!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}