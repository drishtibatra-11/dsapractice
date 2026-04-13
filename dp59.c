#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: push queue elements into stack
    for (int i = 0; i < N; i++) {
        push(dequeue());
    }

    // Step 2: pop stack and print (reversed queue)
    for (int i = 0; i < N; i++) {
        printf("%d ", pop());
    }

    return 0;
}