#include <stdio.h>
#include <stdlib.h>

/* Doubly Linked List Node */
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

/* Function to create doubly linked list */
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

/* Function to traverse and print */
void traverse(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct Node* head = createList(n);

    traverse(head);

    return 0;
}