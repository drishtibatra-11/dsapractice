#include <stdio.h>
#include <string.h>

struct student {
    int rollno;
    char name[20];
    char department[20];
    char course[20];
    int year;
};

int main() {

    struct student s1;
    struct student *ptr = &s1;

    printf("Enter the name of student 1: ");
    scanf("%s", ptr->name);

    printf("Enter the rollno of student 1: ");
    scanf("%d", &ptr->rollno);

    printf("Enter the department of student 1: ");
    scanf("%s", ptr->department);

    printf("Enter the course of student 1: ");
    scanf("%s", ptr->course);

    printf("Enter the year of student 1: ");
    scanf("%d", &ptr->year);

    printf("\nStudent 1 details:\n");
    printf("Name: %s\n", ptr->name);
    printf("Rollno: %d\n", ptr->rollno);
    printf("Department: %s\n", ptr->department);
    printf("Course: %s\n", ptr->course);
    printf("Year: %d\n", ptr->year);

    return 0;
}