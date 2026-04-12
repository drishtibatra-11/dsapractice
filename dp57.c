#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // Empty queue
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL) // Queue becomes empty
        rear = NULL;

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    char operation[20];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (operation[0] == 'e') { // enqueue
            scanf("%d", &value);
            enqueue(value);
        } else if (operation[0] == 'd') { // dequeue
            dequeue();
        }
    }

    return 0;
}