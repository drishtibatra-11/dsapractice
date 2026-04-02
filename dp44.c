#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Check precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If operand → add to output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If '(' → push
        else if (ch == '(') {
            push(ch);
        }
        // If ')' → pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);
}

// Driver
int main() {
    char infix[MAX];
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}