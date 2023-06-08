#include <stdio.h>
#include <curses.h>
#include <unistd.h>

#define BASEPORT 0x378

int main() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
    
  int running = 0;  //Keeps the program running
  int uservariable; //Stores user input
  char onesBinaryString[5]; //Stores the ones digit in binary
  char tensBinaryString[5]; //Stores the tens digit in binary
  
  while (running == 0) {
    //Number
    int number = 69;
    
    //Takes the first and second digits and stores them respectively
    unsigned char tens = number / 10;
    unsigned char ones = number % 10;
  
    //Converts digits to binary strings
    sprintf(onesBinaryString, "0b%04b", ones);
    sprintf(tensBinaryString, "0b%04b", tens);
    
    //Prints what should be displayed
    clear();
    mvprintw(3, 12, "Number: %d", number);
    mvprintw(4, 12, "Tens digit (left display): %d", tens);
    mvprintw(5, 12, "Ones digit (right display): %d", ones);
    mvprintw(7, 12, "Ones digit in binary: %s", onesBinaryString);
    mvprintw(8, 12, "Tens digit in binary: %s", tensBinaryString);
    refresh();

    //Checks for user input
    uservariable = getch();
    
    //Outputs ones binary string
    outb(onesBinaryString, BASEPORT);
    usleep(1000);
    outb(0xFF, BASEPORT);  //Turns all displays off
    usleep(1000);
    
    //Outputs tens binary string
    outb(tensBinaryString, BASEPORT);
    usleep(1000);
    outb(0xFF, BASEPORT);  //Turns all displays off
    usleep(1000);
    
    //Quits if 'q' is pressed
    if (uservariable == 'q') {
      running == 1;
      break;
    }
  }
  usleep(100000);
  
  ioperm(BASEPORT, 3, 0);
  endwin();
  return 0;
}
