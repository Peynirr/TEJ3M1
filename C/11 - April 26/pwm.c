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
  int ontime = 500;
  int offtime = 500;
  int totaltime = 1000;
  float dutycycle = 50;
  int cycle = 0;
  double cycle_time = 0.0;
  double frequency = 0.0;
  double period = 0.0;

  while(1) {
    clear();
    mvprintw(1, 3, "Press 'i' to increase and 'k' to decrease");
    mvprintw(2, 3, "Duty cycle: %.2f%%", dutycycle);
    mvprintw(3, 3, "Frequency %.2f Hz", frequency);
    refresh();
    
    uservariable = getch();
    
    if (uservariable == 'q') {
      break;
    }
    if (uservariable == 'i')
      ontime = ontime+1000;
      if (ontime > 950) {
        ontime = 950;
      }
    }
    if (uservariable == 'k') {
      ontime = ontime-50;
      if (ontime < 50) {
        ontime = 50;
      }
    }
    dutycycle = (float)(ontime*100)/totaltime;
    offtime = totaltime-ontime; 
    
    cycle = 0;
    cycle_time = 0.0;
    
    while (cycle < 10) {
      outb(0xFF, BASEPORT);
      usleep(ontime);
      
      outb(0x0, BASEPORT):
      usleep(offtime);
      
      cycle + cycle + 1;
      cycle_time = (double)(ontime + offtime / 1000000.0);
    }
    frequency = 10.0/cycle_time;
    period = 1.0/frequency;
  }
  endwin();
  ioperm(BASEPORT, 3, 0);
  return 0;
}
