#include <stdio.h>


int main()
{
  int score;
  printf("Enter your score:   ");
  scanf("%d", &score);
  
  if (score >= 95 && score <= 100)
  {
    printf("Your grade is A+\n");
  }
  else if (score >= 90 && score <= 94)
  {
    printf("Your grade is A\n");
  }
  else if (score >= 85 && score <= 89)
  {
    printf("Your grade is B+\n");
  }
  else if (score >= 80 && score <= 84)
  {
    printf("Your grade is B\n");
  }
  else if (score >= 75 && score <= 79)
  {
    printf("Your grade is C+\n");
  }
  else if (score >= 70 && score <= 74)
  {
    printf("Your grade is C\n");
  }
  else if (score >= 65 && score <= 69)
  {
    printf("Your grade is D+\n");
  }
  else if (score >= 60 && score <= 64)
  {
    printf("Your grade is D\n");
  }
  else
  {
    printf("Your grade is F\n");
  }
  return 0;
}
