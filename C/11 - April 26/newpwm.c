#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include </usr/include/sys/io.h>

#define BASEPORT 0x378

int main() {
  initscr();
  cbreak();
  timeout(1);
  noecho();
  curs_set(0);
  
  int uservariable;
  int ontime = 0;
  int offtime = 0;
  int cycle = 0;
  int running = 0;

  while(running == 0) {
    clear();
    mvprintw(1, 3, "Press 'i' to increase and 'k' to decrease");
    mvprintw(2, 3, "Duty cycle: %.2f%% percent", cycle);
    refresh();
    
    uservariable = getch();
    
    outb(0xFF, BASEPORT);
    usleep(ontime);
      
    outb(0x0, BASEPORT):
    usleep(offtime);
    
    if (uservariable == 'q') {
      running = 1;
    }
    if (uservariable == 'i')
      cycle = cycle + 1;
      if (cycle >= 99) {
        cycle = 99;
      }
    }
    if (uservariable == 'k') {
      cycle = cycle - 1;
      if (cycle <= 1) {
        cycle = 1;
      }
    } 
    ontime = cycle*100
    offtime = 100*(100-cycle);
  }
  endwin();
  ioperm(BASEPORT, 3, 0);
  return 0;
}
