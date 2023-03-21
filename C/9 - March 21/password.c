#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char password[100]; //limit of 100 characters
  int length, has_upper = 0, has_lower = 0, has_digit = 0;
  
  printf("Enter your password:  ");
  scanf("%s", &password);
  
  length = strlen(password);
  
  if (length >= 8)
  {
    for (int i = 0; i < length; i++)
    {
      if (isupper(password[i]))
      {
        has_upper = 1;
      }
      else if (islower(password[i]))
      {
        has_lower = 1;
      }
    else if (isdigit(password[i]))
      {
        has_digit = 1;
      }
    }
    
    if (has_upper && has_lower && has_digit)
    {
      printf("Your password is valid.\n");
    }
    else
    {
      printf("Your password is invalid. Please make sure it contains at least one uppercase letter, one lowercase letter, and one digit.\n");
    }
  }
  else
  {
    printf("Your password is too short. Please make sure it contains at least 8 characters.\n");
  }
  return 0;
}

