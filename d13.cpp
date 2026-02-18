// create a structure person having attributes as age and weight . access its structure variables using pointers
#include<stdio.h>
struct person{
    int age;
    float weight;
};
int main()
{
    struct person p1;
    struct person *ptr = &p1;

    printf("Enter age: ");
    scanf("%d", &ptr->age);

    printf("Enter weight: ");
    scanf("%f", &ptr->weight);

    printf("\nPerson details:\n");
    printf("Age: %d\n", ptr->age);
    printf("Weight: %.2f\n", ptr->weight);

    return 0;
}