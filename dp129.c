#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *a, *b, *c;

    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));

    a->data = 1;
    b->data = 2;
    c->data = 3;

    a->next = b;
    b->next = c;
    c->next = a;

    struct Node *slow = a;
    struct Node *fast = a;

    int cycle = 0;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cycle = 1;
            break;
        }
    }

    if(cycle)
        printf("Cycle Found");
    else
        printf("No Cycle");

    return 0;
}