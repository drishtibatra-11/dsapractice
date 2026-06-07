#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *random;
};

struct Node* createNode(int data) {
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->next = NULL;
    node->random = NULL;

    return node;
}

struct Node* copyRandomList(struct Node* head) {

    if (head == NULL)
        return NULL;

    struct Node* curr = head;

    /* Step 1: Insert copied nodes */
    while (curr) {
        struct Node* copy = createNode(curr->data);

        copy->next = curr->next;
        curr->next = copy;

        curr = copy->next;
    }

    /* Step 2: Set random pointers */
    curr = head;

    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;

        curr = curr->next->next;
    }

    /* Step 3: Separate lists */
    curr = head;

    struct Node* copyHead = head->next;

    while (curr) {

        struct Node* copy = curr->next;

        curr->next = copy->next;

        if (copy->next)
            copy->next = copy->next->next;

        curr = curr->next;
    }

    return copyHead;
}

void printList(struct Node* head) {

    while (head) {

        printf("Node=%d ", head->data);

        if (head->random)
            printf("Random=%d\n", head->random->data);
        else
            printf("Random=NULL\n");

        head = head->next;
    }
}

int main() {

    struct Node* n1 = createNode(1);
    struct Node* n2 = createNode(2);
    struct Node* n3 = createNode(3);

    n1->next = n2;
    n2->next = n3;

    n1->random = n3;
    n2->random = n1;
    n3->random = n2;

    struct Node* copied = copyRandomList(n1);

    printf("Copied List:\n");
    printList(copied);

    return 0;
}