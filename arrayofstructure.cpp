#include<stdio.h>
#include<string.h>
typedef struct student {
    int rollno;
    char name[20];
    char department[20];
    char course[20];
    int year;
} st;
int main() {
    st s[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", s[i].name);

        printf("Enter the rollno of student %d: ", i + 1);
        scanf("%d", &s[i].rollno);

        printf("Enter the department of student %d: ", i + 1);
        scanf("%s", &s[i].department);

        printf("Enter the course of student %d: ", i + 1);
        scanf("%s", &s[i].course);

        printf("Enter the year of student %d: ", i + 1);
        scanf("%d", &s[i].year);
    }
    printf("\nStudent details:\n");
    for (int i = 0; i < 10; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Rollno: %d\n", s[i].rollno);
        printf("Department: %s\n", s[i].department);
        printf("Course: %s\n", s[i].course);
        printf("Year: %d\n", s[i].year);
        printf("\n");
    }
    return 0;
}
