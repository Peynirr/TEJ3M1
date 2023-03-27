#include <stdio.h>


int main()
{
  int current_num = 0;
  {
    while (current_num <= 10) {
      if (current_num % 2 == 0) {
        printf("%d\n", current_num);
      }
      current_num++; 
    }
  }
  return 0;
}

