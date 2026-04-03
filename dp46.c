#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Initialize queue
void init(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Enqueue
void enqueue(struct Queue* q, int x) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1) q->front = 0;

    q->arr[++q->rear] = x;
}

// Dequeue (not required but included)
int dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->arr[q->front++];
}

// Display
void display(struct Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

// Driver
int main() {
    int n, x;
    struct Queue q;

    init(&q);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    display(&q);

    return 0;
}