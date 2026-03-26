#include<stdio.h>
#include<stdlib.h>
struct Node {
    char data;
    struct Node* next;
};
void push(char x);
void display();
void reverse();

struct Node* top = NULL;
int main() {
    char x;
    int n;
    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the character to be pushed: ");
        scanf(" %c", &x);
        push(x);
    }
    reverse();
    display();
}
void push(char x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
void reverse() {
    struct Node* temp = NULL;
    struct Node* temp2 = top;
    struct Node* temp3 = NULL;
    while (temp2 != NULL) {
        temp3 = temp2->next;
        temp2->next = temp;
        temp = temp2;
        temp2 = temp3;
    }
    top = temp;

}
void display()
{
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%c\n", temp->data);
        temp = temp->next;
    }
}
