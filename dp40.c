

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, x;

    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    // Step 1: Find length and last node
    int len = 1;
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
        len++;
    }

    // Step 2: Make it circular
    last->next = head;

    // Step 3: Normalize k
    k = k % len;

    // Step 4: Find new last node (n-k steps)
    int steps = len - k;
    struct Node* newLast = head;
    for (int i = 1; i < steps; i++) {
        newLast = newLast->next;
    }

    // Step 5: Set new head
    struct Node* newHead = newLast->next;
    newLast->next = NULL;

    // Step 6: Print result
    temp = newHead;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}