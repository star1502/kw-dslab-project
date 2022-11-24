#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "computeTime.hpp"
#include "memoryWhatNum.hpp"
#include "memoryWhatPic.hpp"
#include "responseTime.hpp"

using namespace std;

void mySigHandler(int signum) { exit(0); }

int main(void) {
    // Redefine SIGINT handler
    if (signal(SIGINT, mySigHandler) == SIG_ERR) {
        perror("FAILED to Redefine SIGINT handler");
    }

    while (1) {
    }

    return 0;
}
