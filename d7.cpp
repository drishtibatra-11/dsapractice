//nested structures
#include<stdio.h>
int main()
{
    typedef struct student{
        int rollno;
        char name[20];
    }student;
typedef struct parent{
    char name[20];
    student s;
}parent;
parent p[3];
for (int i = 0; i < 3; i++)
{
    printf("enter the name of parent %d",i+1);
    scanf("%s",p[i].name);
    printf("enter the rollno of student %d",i+1);
    scanf("%d",&p[i].s.rollno);
    printf("enter the name of student %d",i+1);
    scanf("%s",p[i].s.name);
}
for (int i = 0; i < 3; i++)
{
    printf("the name of parent %d is %s\n",i+1,p[i].name);
    printf("the rollno of student %d is %d\n",i+1,p[i].s.rollno);
    printf("the name of student %d is %s\n",i+1,p[i].s.name);
}
}