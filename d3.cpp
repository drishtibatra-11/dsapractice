#include<stdio.h>
int main()
{
   typedef  struct employee{
        char name[20];
        char department[20];
        int salary;
    }pw;
    struct employee a;
    struct employee b;
    printf("enter the name of the employee");
    scanf("%s",&a.name);
    printf("enter the name of the department");
    scanf("%s",&a.department);
    printf("enter the salary of the employee");
    scanf("%d",&a.salary);
    printf("%s\n",a.name);
    printf("%s\n",a.department);
    printf("%d\n",a.salary);
    printf("enter the name of the employee");
    scanf("%s",&b.name);
    printf("enter the name of the department");
    scanf("%s",&b.department);
    printf("enter the salary of the employee");
    scanf("%d",&b.salary);
    printf("%s\n",b.name);
    printf("%s\n",b.department);
    printf("%d\n",b.salary);
    return 0;
}

