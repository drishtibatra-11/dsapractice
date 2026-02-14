#include<stdio.h>
int main()
{
struct person{
    char name[10];
    int salary;
    int age;
};
struct person a;
struct person b;
printf ("enter the name of the first person");
scanf("%s",&a.name);
printf("enter the age of second person");
scanf("%d",&b.age);
printf("%s\n",a.name);
printf("%d\n",b.age);
return 0;
}
