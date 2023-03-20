#include <stdio.h>

int main()
{
char name [30];
printf("Enter your name:  ");
fgets(name, 30, stdin);

int age;
printf("Enter your age:   ");
scanf("%d", &age);

int year;
printf("Year:   ");
scanf("%d", &year);

char school[30];
printf("Enter your school name:   ");
fgets(school, 30, stdin);

int grade;
printf("Enter your grade:  ");
scanf("%d", &grade);

//Output
printf("Your name is %s \n", name);
printf("Your age is %d \n", age);
printf("The year is %d \n", year);
printf("You go to %s \n", school);
printf("You are in grade %d \n", grade);

return 0;
}
