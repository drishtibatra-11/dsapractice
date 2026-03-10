#include<stdio.h>
#include<stdlib.h>
struct birth{
    int day;
    int month;
    int year;
};
struct employee{
    int id;
    char name[20];
    float salary;
    struct birth b;
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
        printf("enter the birth day month year");
        scanf("%d%d%d",&emp[i].b.day,&emp[i].b.month,&emp[i].b.year);
    }
    printf("employee details are\n");
    for(i=0;i<n;i++)
    {
        printf("id=%d name=%s salary=%.2f birth=%d/%d/%d\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].b.day,emp[i].b.month,emp[i].b.year);
    }
    return 0;
}