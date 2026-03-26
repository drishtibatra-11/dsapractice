
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void push(int x);
void pop();
void display();


struct Node* top = NULL;
int main() {
    int x, n;
    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the number to be pushed: ");
        scanf("%d", &x);
        push(x);
    }

    display();
    pop();
    pop();

    return 0;
}

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct Node* temp = top;
        printf("Popped element: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display()
 
{
if (top==NULL)
{
   printf("stack empty");
}
   else
   {
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
   }
}
