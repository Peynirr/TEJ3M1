#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <sys/io.h>

#define BASEPORT 0x378

unsigned char digits[10] = {
  0b0000, //0
  0b0001, //1
  0b0010, //2
  0b0011, //3
  0b0100, //4
  0b0101, //5
  0b0110, //6
  0b0111, //7
  0b1000, //8
  0b1001 //0
};

int main() {
  initscr();
  noecho();
  curs_set(1);
    
  int running = 0;
  int uservariable;
  
  unsigned char number;
  number = 15;
  
  while (running == 0) {
    clear();
    mvprintw(3, 12, "Number: %hhu", number);
    mvprintw(4, 12, "Tens digit: %hhu", tens);
    mvprintw(5, 12, "Ones digit: %hhu", ones);
    refresh();
    
    uservariable = getch();
    
    unsigned char tens = number / 10;
    unsigned char ones = number % 10;
    
    outb(digits[tens], BASEPORT);
    usleep(1000);
    
    outb(digits[ones], BASEPORT);
    usleep(1000);
    
    if (uservariable == 'q') {
      running == 1;
      break;
    }
  }
  ioperm(BASEPORT, 3, 0);
  endwin();
  return 0;
}
