#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*link;
};
struct node*createlist(struct node*start);
struct node*insertatthebeginning(struct node*start,int data);
struct node*insertattheend(struct node*start,int data);
struct node*createlist(struct node*start)
{
    int n,data,i;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
   printf("enter the data to be enetered\n");
    scanf("%d",&data);
    start=insertatthebeginning(start,data);
    for(i=2;i<=n;i++)
    {
        printf("enter the data to be enetered\n");
        scanf("%d",&data);
        start=insertattheend(start,data);
    }
    return start;
}
struct node*insertatthebeginning(struct node*start,int data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
}
struct node*insertattheend(struct node*start,int data)
{
    struct node*temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        p=start;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    return start;
}
int main()
{
    struct node*start=NULL;
    start=createlist(start);
    struct node*temp=start;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->info);
        temp=temp->link;
    }
    printf("null\n");
}