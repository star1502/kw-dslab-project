#include <iostream>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "computeTime.hpp"
#include "frontEnd.hpp"
#include "memoryWhatNum.hpp"
#include "memoryWhatPic.hpp"
#include "responseTime.hpp"

using namespace std;

void mySigHandler(int signum) {
    char selection = '0';
    cout << "Do you want to Quit? (y or n)" << endl << "Choose -> ";
    cin >> selection;
    toupper(selection);

    if (selection == 'Y') {
        return;
    } else
        exit(0);
}

int main(void) {
    // Redefine SIGINT handler
    if (signal(SIGINT, mySigHandler) == SIG_ERR) {
        perror("FAILED to Redefine SIGINT handler");
    }

    cout << "welcome to game! " << endl;
    while (1) {
        cout << "Choose the game you want to play" << endl
             << "1. Reaction Time " << endl
             << "2. Calculation time" << endl
             << "3. Memory the number " << endl
             << "4. Memory the picture" << endl
             << "Choose -> ";

        unsigned short selection = -0;
        cout << "<< select: ";
        cin >> selection;

        switch (selection) {
        case 1:
            responseTime();
            break;
        case 2:
            computeTime();
            break;
        case 3:
            memoryWhatNum();
            break;
        case 4:
            memoryWhatPic();
            break;
        default:
            cout << "Wrong Selection! " << endl;
            break;
        }
    }

    return 0;
}
