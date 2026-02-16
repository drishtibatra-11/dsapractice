/*cricketer record*/
#include<stdio.h>
int main()
{
 typedef struct cricketer{
        char name[20];
        int age;
        int testmatch;
    }cricketer;
    cricketer arr[10];
    int i;
    for (i=0;i<10;i++)
    {
        printf("enter the name of the cricketer");
        scanf("%s",arr[i].name);
        printf("enter the age of the cricketer");
        scanf("%d",&arr[i].age);
        printf("enter the number of test matches played by the cricketer");
        scanf("%d",&arr[i].testmatch);
    }
    for (i=0;i<10;i++)
    {
        printf("%c\n",arr[i].name);
        printf("%d\n",arr[i].age);
        printf("%d\n",arr[i].testmatch);
    }
    return 0;
}