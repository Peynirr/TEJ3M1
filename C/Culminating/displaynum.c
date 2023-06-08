#include <stdio.h>
#include <curses.h>
#include <unistd.h>

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
    int number = 21;
    
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
    
    //This is what would be outputted to the parallel port for the ones digit - SAMPLE
    mvprintw(10, 12, "outb(%s, BASEPORT)", onesBinaryString);
    
    refresh();

    //Checks for user input
    uservariable = getch();
    
    //Quits if 'q' is pressed
    if (uservariable == 'q') {
      running == 1;
      break;
    }
  }
  usleep(100000);
  
  endwin();
  return 0;
}
