#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

void dequeue() {
    if(front == -1 || front > rear)
        return;

    front++;
}

void display() {
    for(int i=front;i<=rear;i++)
        printf("%d ", queue[i]);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    dequeue();

    display();

    return 0;
}