#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp;

    for(int i = 5; i >= 1; i--) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Element = %d", slow->data);

    return 0;
}