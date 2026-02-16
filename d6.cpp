//
#include<stdio.h>
int main()
{
    typedef struct date{
        int date;
        int month;
        int year;
    }date;
    date d1,d2;
    printf("enter the date 1");
    scanf("%d",&d1.date);
    printf("enter the month 1");
    scanf("%d",&d1.month);
    printf("enter the year 1");
    scanf("%d",&d1.year);
    printf("enter the date 2");
    scanf("%d",&d2.date);
    printf("enter the month 2");
    scanf("%d",&d2.month);
    printf("enter the year 2");
    scanf("%d",&d2.year);
    if ( d1.date == d2.date && d1.month == d2.month && d1.year == d2.year)
    {
        printf("the two dates are same");
    }
    else
    {
        printf("the two dates are different");
    }
}