// structure pointer
#include<stdio.h>
#include<string.h>
typedef struct student{
    int rollno;
    char name[20];
    char department[20];
    char course[20];
    int year;
}student;
int main()
{
    student s1,s2;
    student *ptr1 = &s1;
    printf("enter the name of student 1");
    scanf("%s",ptr1->name);
    printf("enter the rollno of student 1");
    scanf("%d",&ptr1->rollno);
    printf("enter the department of student 1");
    scanf("%s",ptr1->department);
    printf("enter the course of student 1");
    scanf("%s",ptr1->course);
    printf("enter the year of student 1");
    scanf("%d",&ptr1->year);
    printf("student 1 details:\n");
    printf("name: %s\n",*ptr1->name);
    printf("rollno: %d\n",*ptr1->rollno);
    printf("department: %s\n",*ptr1->department);
    printf("course: %s\n",*ptr1->course);
    printf("year: %d\n",*ptr1->year);
}