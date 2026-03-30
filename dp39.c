#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    if (n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create first node
    scanf("%d", &x);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = x;
    head->next = head;  // circular link
    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;

        newNode->next = head;   // point to head
        temp->next = newNode;   // link previous node
        temp = newNode;
    }

    // Traversal
    struct Node* ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    return 0;
}