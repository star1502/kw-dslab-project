#include "frontEnd.hpp"
#include "computeTime.hpp"
#include "memoryWhatNum.hpp"
#include "memoryWhatPic.hpp"
#include "responseTime.hpp"

#include <ctime>
#include <iostream>
#include <ncurses.h>
#include <signal.h>
#include <unistd.h>

using namespace std;
void wannaQuit(int signum) {
    char selection = '0';
    cout << "Do you want to Quit? (y or n)" << endl << "Choose -> ";
    cin >> selection;
    toupper(selection);

    if (selection == 'Y') {
        return;
    } else
        exit(0);
}

void responseTime(void) {
    clock_t timeStarted = 0, timePressed = 0, resTime[5];
    char detectKey;
    int i; // for Loop

    while (1) {
        cout << "You choosed Reaction Time!" << endl;

        // Measuring Reaction Time : do 5 times
        for (i = 0; i < 5; i++) {
            // CLEAR Input buffer
            cin.clear();

            // READY
            cout << "Loop :" << i + 1 << endl;
            usleep(waitHowMuchTime()); // WAIT

            // SINCE Start -> UNTIL Pressed Key
            cout << "Press ENTER KEY to react" << endl;
            timeStarted = clock();
            cin >> detectKey; // DETECT Keyboard Input
                              // ?????????????????????????????
            timePressed = clock();
            resTime[i] =                   // RECORD Reaction Time
                timePressed - timeStarted; // SINCE Start -> UNTIL Pressed Key

            // PRINT Response Time
            if (i != 4) {
                cout << "You responsed in " << resTime[i] << "[ms]" << endl;
                cout << "Press ENTER KEY to preceed" << endl;
                cin >> detectKey; //?????????????????????????????
            }
        }

        // Print FINAL RESULT
        cout << "Reaction time record" << endl;
        for (i = 0; i < 5; i++)
            cout << "\t Loop " << i + 1 << " : " << resTime[i] << "[ms]"
                 << endl;
        cout << endl;

        // ASK the user
        cout << "Do you want to play more? (y or n)" << endl << "Choose -> ";
        char selection = '0';
        cin >> selection;
        toupper(selection);
        if (selection == 'N') {
            return;
        }
    }
}
void computeTime(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    ToBeComputed *use;
    unsigned long answer, userAnswer;
    string equation;
    clock_t timeStarted = 0, timePressed = 0;
    bool isFailed;

    while (life > 0) {
        std::cin.ignore();

        //  variable Initialze
        use = new ToBeComputed;
        use->myinit(level);
        answer = use->getAnswer();
        equation = use->getFormula();
        isFailed = false;

        std::cout << "ANS =====  " << answer << " =====" << std::endl;

        // Print formula
        std::cout << "Calculate " << equation << " in 3 sec" << std::endl;
        std::cout << "Your ans : ";

        std::cout << "USR =====  " << userAnswer << " =====" << std::endl;

        // COUNTDOWN
        timeStarted = clock();
        std::cin >> userAnswer;

        // CHECK : isWrong?
        if (answer == userAnswer) {
            timePressed = clock();
            std::cout << "Correct!" << std::endl;
        } else {
            timePressed = clock();
            std::cout << "Wrong Answer!" << std::endl;
            isFailed = true;
        }

        // CHECK : isTimeOut?
        if (timePressed - timeStarted > 3000) {
            std::cout << "Time Out!" << std::endl;
            isFailed = true;
        }

        if (isFailed == true) {
            life--;
            std::cout << life << " times remaining" << std::endl;
        }

        level++;
        delete use;
    }

    std::cout << "You Dead!" << std::endl;
}

void memoryWhatNum(void) {
    while (1) {
    }
}
void memoryWhatPic(void) {
    while (1) {
    }
}
