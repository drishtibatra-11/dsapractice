//linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* createnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
int main()
{
    struct node* head = createnode(10);
    struct node* second = createnode(20);
    struct node* third = createnode(30);
    head->next=second;
    second->next=third;
    third->next=NULL;
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("null\n");
}
