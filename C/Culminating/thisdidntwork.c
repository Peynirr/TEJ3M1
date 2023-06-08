#include <stdio.h>
#include <curses.h>
#include <unistd.h>

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
  0b1001  //9
};

int main() {
  initscr();
  noecho();
  curs_set(1);
    
  int running = 0;  //Used to keep the program running
  int uservariable; //Used to store user input
  int number; //Used to input a number
  
  while (running == 0) {
    //Number
    number = 69;
    
    //Takes the first and second digits and stores them respectively
    unsigned char tens = number / 10;
    unsigned char ones = number % 10;
    
    //Converts the binary into a string
    char onesBinaryString[5];
    char tensBinaryString[5];
    
    //Retrieves the index number in the binary array
    unsigned char onesBinary = digits[ones];
    unsigned char tensBinary = digits[tens];
    
    //Converts digits to binary strings
    sprintf(onesBinaryString, "0b%04b", onesBinary);
    sprintf(tensBinaryString, "0b%04b", tensBinary);
    
    //Prints what should be displayed
    clear();
    mvprintw(3, 12, "Number: %d", number);
    mvprintw(4, 12, "Tens digit (left display): %d", tens);
    mvprintw(5, 12, "Ones digit (right display): %d", ones);
    mvprintw(7, 12, "Ones digit in binary: %s", onesBinaryString);
    mvprintw(8, 12, "Tens digit in binary: %s", tensBinaryString);
    refresh();
    
    //checks for user input
    uservariable = getch();
    
    outb(onesBinaryString, BASEPORT);
    usleep(1000);
    
    outb(tensBinaryString, BASEPORT);
    usleep(1000);
    
    //Quits if 'q' is pressed
    if (uservariable == 'q') {
      running == 1;
      break;
    }
  }
  ioperm(BASEPORT, 3, 0);
  endwin();
  return 0;
}
