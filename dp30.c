#include<stdio.h>

#define MAX 5
int stack[MAX];
int TOP = -1;
void push(int x);
void display();
void pop();

int main()
{
    int x, i;
    for(i=0; i<MAX-1; i++)
    {
    printf("Enter the number to be pushed: ");
    scanf("%d", &x);

    push(x);
    }

    display(); 
    pop();

    return 0;
}
void push(int x)
{
    if (TOP == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        TOP++;
        stack[TOP] = x;
    }
}

void display()
{
    if (TOP == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (int i = TOP; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
void pop()
{
    if (TOP == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int element = stack[TOP];
        TOP--;
        printf("Popped element: %d\n", element);
    }
//.
