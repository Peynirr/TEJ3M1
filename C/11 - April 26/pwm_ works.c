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
  curs_set(1);
  
  int uservariable;
  int ontime = 0;
  int offtime = 10000;
  float dutycycle = 0;
  int running = 0;

  while(running == 0) {
    clear();
    mvprintw(1, 12, "Press 'i' to increase and 'k' to decrease");
    mvprintw(2, 12, "Press 'q' to quit the program.);
    mvprintw(3, 12, "Duty cycle: %.2f%%", dutycycle);
    refresh();
    
    uservariable = getch();
    
    outb(0xFF, BASEPORT);
    usleep(ontime);
    
    outb(0x0, BASEPORT);
    usleep(offtime);
    
    if (uservariable == 'q') {
      running == 1
      break;
    }
    if (uservariable == 'i')
      ontime = ontime+100;
      if (ontime >= 10000) {
        ontime = 10000;
      }
    }
    if (uservariable == 'k') {
      ontime = ontime-100;
      if (ontime <= 0) {
        ontime = 0;
      }
    }
    dutycycle = (float)(ontime*100)/10000;
    offtime = 10000-ontime; 
  }
  ioperm(BASEPORT, 3, 0);
  endwin();
  return 0;
}
