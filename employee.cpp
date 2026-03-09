#include<stdio.h>
#include<stdlib.h>
struct employee{
    int id;
    char name[20];
    float salary;
};
struct employee emp[100];
int main()
{
    int n,i;
    printf("enter the number of employees");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the id");
        scanf("%d",&emp[i].id);
        printf("enter the name");
        scanf("%s",emp[i].name);
        printf("enter the salary");
        scanf("%f",&emp[i].salary);
    }
    printf("employee details are\n");
    for(i=0;i<n;i++)
    {
        printf("id=%d name=%s salary=%.2f\n",emp[i].id,emp[i].name,emp[i].salary);
    }
    return 0;
}