// structure by call by value
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
    s1.rollno = 10;
    s2.rollno = 20;
    s1.name[0] = 'A';
    s2.name[0] = 'B';
    s1.department[0] = 'C';
    s2.department[0] = 'D';
    s1.course[0] = 'E';
    s2.course[0] = 'F';
    s1.year = 2020;
    s2.year = 2021;
}
int main()
{
    student s1,s2;
    strcpy(s1.name,"Alice");
    strcpy(s2.name,"Bob");

    s1.rollno = 1;
    s2.rollno = 2;
    strcpy(s1.department,"CSE");
    strcpy(s2.department,"ECE");
    strcpy(s1.course,"DSA");
    strcpy(s2.course,"OS");
    s1.year = 2019;
    s2.year = 2020;
    display(s1,s2);
    printf("student 1 details:\n");
    printf("name: %s\n",s1.name);
    printf("rollno: %d\n",s1.rollno);
    printf("department: %s\n",s1.department);
    printf("course: %s\n",s1.course);
    printf("year: %d\n",s1.year);
    printf("student 2 details:\n");
    printf("name: %s\n",s2.name);
    printf("rollno: %d\n",s2.rollno);
    printf("department: %s\n",s2.department);
    printf("course: %s\n",s2.course);
    printf("year: %d\n",s2.year);
}
//structures are passed by value, so the changes made to the structure variables inside the display function do not affect the original structure variables in the main function.