#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node *head = NULL, *temp;

    for(int i = 3; i >= 1; i--) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    struct Node *prev = NULL, *curr = head, *next;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    printList(head);
    return 0;
}