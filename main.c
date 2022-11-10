#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include "computeTime.h"
#include "memoryWhatNum.h"
#include "memoryWhatPic.h"
#include "myVector.h"
#include "responseTime.h"

int main(void) {
    WINDOW *window1;
    WINDOW *window2;

    initscr();

    if (has_colors() == FALSE) {
        puts("Terminal does not support colors!\n");
        endwin();
        return 1;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }

    refresh;

    window1 = newwin(18, 80, 0, 0);
    window2 = newwin(6, 80, 18, 0);

    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(window2, COLOR_PAIR(2));

    wprintw(window1, "hello");
    wprintw(window2, "5424242542452");

    wrefresh(window1);
    wrefresh(window2);

    getch();

    endwin();

    return 0;
}

/*
void mySigHandler(int signum) {
}

int main(void) {
    // Redefine SIGINT handler
    if (signal(SIGINT, mySigHandler) == SIG_ERR) {
        perror("signal() error!");
    }

    return 0;
}
*/
