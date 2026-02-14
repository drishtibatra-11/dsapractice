#include<stdio.h>
int main()
{
    struct book{
        char name[20];
        char author[20];
        int price;
    };
    struct book a;
    printf("enter the name of the book");
    scanf("%s",&a.name);
    printf("enter the name of the author");
    scanf("%s",&a.author);
    printf("enter the price of the book");
    scanf("%d",&a.price);
    printf("%s\n",a.name);
    printf("%s\n",a.author);
    printf("%d\n",a.price);
    return 0;
}