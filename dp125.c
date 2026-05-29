#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if(top == -1)
        printf("Underflow\n");
    else
        top--;
}

void display() {
    for(int i=top;i>=0;i--)
        printf("%d ", stack[i]);
}

int main() {
    push(10);
    push(20);
    push(30);

    pop();

    display();

    return 0;
}