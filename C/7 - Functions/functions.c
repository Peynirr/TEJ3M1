//Omercan
#include <stdio.h>
#include <math.h>

int area();

int main() 
{
  int length;
    printf("Enter the length:  ");
    scanf("%d", &length);

  int width;
    printf("Enter the width:  ");
    scanf("%d", &width);

  int result = area(length, width);
  
  printf("The area is %d.\n", result);
  return 0;
}

int area(int length, int width) 
{
  int answer = length*width;
  return answer;
}
