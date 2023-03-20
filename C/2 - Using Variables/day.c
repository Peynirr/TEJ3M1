#include <stdio.h>

int main()

{
int day = 1;
int monthDay = 3;
int year = 2023; 
char dayOfWeek[] = "Friday";
char month[] = "March";

printf("Today is %s %d, %d\n", month, monthDay, year); //displays the month, day, year
printf("It is a day %d.\n", day); //displays the day on our schedule
printf("It is a %s.\n", dayOfWeek); //displays the day of the week

return 0;
}
