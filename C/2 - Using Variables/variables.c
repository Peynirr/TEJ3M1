#include <stdio.h>

int main()

{
//Variables
char myName[] = "Omercan"; //my name
int age = 17; //my age
int nextAge = 18; //age next year
float balance = 2.20;

//Print Variables
printf("My name is %s.\n", myName);
printf("My age is %d.\n", age);
printf("I will be %d next year.\n", nextAge);
printf("I have $%.2f in my bank account. I'm poor.\n", balance);

return 0;
}
