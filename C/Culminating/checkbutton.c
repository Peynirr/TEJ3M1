#include <curses.h>
#include <sys/io.h>

#define BASEPORT 0x378
#define BUTTON 0b100000000 //location of the button (pin 9)

int main() {
  initscr();
  cbreak();
  timeout(1);
  noecho();
  curs_set(1);
  
  while (1) {
    int status = inb_p(BASEPORT+1) & BUTTON;
    if (status != 0) {
      mvprintw(1, 12, "Button pressed");
    }
    else {
      mvprint(1, 12, "Button not pressed");
    }
    refresh();
  }
  ioperm(BASEPORT, 3, 0);
  endwin();
  return 0;
}
