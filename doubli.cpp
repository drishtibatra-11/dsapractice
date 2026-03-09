#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
}*head,*last;
int main()
{
    int n,data;
    head=NULL;
    last=NULL;
    printf("enter the total numbers of nodes in list");
    scanf("%d",&n);
    createlist(n);
    displaylist();
    return 0;
}
void createlist(int n)
{
    int i, data;
    struct node*newnode;
    if(n>=1)
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter data of 1 node");
    scanf("%d",&data);
    head->data=data;
    head->prev=NULL;
    head->next=NULL;
    last=head;
    for(i=2;i<=n;i++)
    {
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter a data of second ");
scanf("%d",&data);
newnode->data=data;
newnode->prev=last;
newnode->next=NULL;
last->next=newnode;
last=newnode;
    }
}
void displaylist()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("null\n");
    }

}