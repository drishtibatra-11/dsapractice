//pass by value
#include<stdio.h>
#include<string.h>
typedef struct student{
    int rollno;
    char name[20];
    char department[20];
    char course[20];
    int year;
}student;
void display (student s1,student s2)
{
    
if(s1.rollno == s2.rollno && s1.year == s2.year && strcpy(s1.name,s2.name)
== 0 && strcpy(s1.department,s2.department) == 0 && strcpy(s1.course,s2.course) == 0)
{
    printf("the two students are same");
}
else
{
    printf("the two students are different");
}
}
int main()
{
    student s1,s2;
    printf("enter the name of student 1");
    scanf("%s",s1.name);
    printf("enter the rollno of student 1");
    scanf("%d",&s1.rollno);
    printf("enter the department of student 1");
    scanf("%s",s1.department);
    printf("enter the course of student 1");
    scanf("%s",s1.course);
    printf("enter the year of student 1");
    scanf("%d",&s1.year);
    printf("enter the name of student 2");
    scanf("%s",s2.name);
    printf("enter the rollno of student 2");
    scanf("%d",&s2.rollno);
    printf("enter the department of student 2");
    scanf("%s",s2.department);
    printf("enter the course of student 2");
    scanf("%s",s2.course);
    printf("enter the year of student 2");
    scanf("%d",&s2.year);
    display(s1,s2);
}