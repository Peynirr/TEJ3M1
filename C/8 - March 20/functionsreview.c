#include <stdio.h>

int add(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int subtract(int a, int b);

int main()
{
  int num1;
  printf("Enter a number:   ");
  scanf("%d", &num1);
  
  int num2;
  printf("Enter another number:   ");
  scanf("%d", &num2);
  
  int result1 = add(num1, num2);
  int result2 = multiply(num1, num2);
  int result3 = divide(num1, num2);
  int result4 = subtract(num1, num2);
  
  printf("The result of %d and %d is %d.\n", num1, num2, result1);
  printf("The product of %d and %d is %d.\n", num1, num2, result2);
  printf("The result when dividing %d and %d is %d.\n", num1, num2, result3);
  printf("The difference of %d and %d is %d.\n", num1, num2, result4);
  return 0;
}

int add(int a, int b)
{
  int sum = a+b;
  return sum;
}

int multiply(int a, int b)
{
  int product = a*b;
  return product;
}

int divide(int a, int b)
{
  int quotient = a/b;
  return quotient;
}

int subtract(int a, int b)
{
  int difference = a-b;
  return difference;
}
