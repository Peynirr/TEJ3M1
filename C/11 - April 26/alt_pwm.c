#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main() {
  initscr();
  cbreak();
  timeout(1);
  noecho();
  curs_set(1);
  
  int uservariable;
  int ontime = 0;
  int offtime = 0;
  int cycle = 0;
  int running = 0;

  while(running == 0) {
    clear();
    mvprintw(1, 13, "Press 'i' to increase and 'k' to decrease");
    mvprintw(2, 13, "Duty cycle: %d percent", cycle);
    mvprintw(3, 13, "Ontime: %d", ontime);
    mvprintw(4, 13, "Offtime: %d", offtime);
    refresh();
    
    uservariable = getch();
   
    outb(0xFF, BASEPORT);
    usleep(ontime);
      
    outb(0x0, BASEPORT):
    usleep(offtime);
    
    if (uservariable == 'q') {
      running == 1;
      break;
    }
    if (uservariable == 'i') {
      cycle = cycle+1;
      if (cycle >= 100) {
        cycle = 100;
      }
    }
    if (uservariable == 'k') {
      cycle = cycle-1;
      if (cycle <= 0) {
        cycle = 0;
      }
    }
    ontime = cycle*100;
    offtime = (100-cycle)*100; 
  }
  endwin();
  ioperm(BASEPORT, 3, 0);
  return 0;
}
