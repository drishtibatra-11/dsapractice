#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    char* token = strtok(exp, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        // If operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            int res;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            push(&stack, res);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

// Driver
int main() {
    char exp[] = "2 3 1 * + 9 -";
    int result = evaluatePostfix(exp);
    printf("%d\n", result);  // Output: -4
    return 0;
}