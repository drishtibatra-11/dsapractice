#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};
struct node* insertatthebeginning(struct node*start,int data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
}

struct node* insertattheend(struct node*start,int data)
{
    struct node *temp,*p;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    
    if(p->link !=NULL)
    {
        p->link=temp;
        temp->link=NULL;
    }
    
    return start;
}

struct node* createlist(struct node*start,int data)
{
    printf("enter the number of nodes\n");
    int n;
    scanf("%d",&n);
    printf("enter the data\n");
    scanf("%d",&data);
    start=insertatthebeginning(start,data);
    for(int i=2;i<=n;i++)
    {
        printf("enter the data\n");
        scanf("%d",&data);
        start = insertattheend(start,data);
    }
    return start;
}
int main()
{
    struct node*start=NULL;
    int data;
    start=createlist(start,data);
    struct node*temp=start;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->info);
        temp=temp->link;
    }
    printf("null\n");
}