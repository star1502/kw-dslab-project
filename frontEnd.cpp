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

void responseTime(void) {
    clock_t timeStarted = 0, timePressed = 0, resTime[5];
    char detectKey;
    int i; // for Loop

    initscr();

    // Initialize window
    WINDOW *scr_Restime_Instruct = newwin(4, 40, 3, 3);
    WINDOW *scr_Restime_usrRsltPrint = newwin(7, 40, 8, 3);

    mvprintw(0, 0, "You choosed Reaction Time!");
    refresh();

    // Doing game
    char selection = '0';
    while (selection == 'N') {
        wclear(scr_Restime_Instruct);
        wclear(scr_Restime_usrRsltPrint);
        box(scr_Restime_Instruct, 0, 0);     // added for easy viewing
        box(scr_Restime_usrRsltPrint, 0, 0); // added for easy viewing
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrRsltPrint);

        // Measuring Reaction Time : do 5 times
        for (i = 0; i < 5; i++) {
            move(1, 0);
            // CLEAR Input buffer
            std::cin.clear();

            // READY
            mvwprintw(scr_Restime_Instruct, 1, 1, "Ready...");
            mvwprintw(scr_Restime_usrRsltPrint, 1 + i, 1, "Loop ");
            mvwprintw(scr_Restime_usrRsltPrint, 1 + i, 6,
                      to_string(i + 1).c_str());
            mvwprintw(scr_Restime_usrRsltPrint, 1 + i, 8, ":");
            move(1, 0);
            wrefresh(scr_Restime_Instruct);
            wrefresh(scr_Restime_usrRsltPrint);
            usleep(waitHowMuchTime()); // WAIT

            // SINCE Start -> UNTIL Pressed Key
            mvwprintw(scr_Restime_Instruct, 1, 1, "PRESS ANY KEY!");
            move(1, 0);
            wrefresh(scr_Restime_Instruct);
            timeStarted = clock();
            getch();
            timePressed = clock();
            resTime[i] =                   // RECORD Reaction Time
                timePressed - timeStarted; // SINCE Start -> UNTIL Pressed Key

            // PRINT Response Time
            mvwprintw(scr_Restime_usrRsltPrint, 1 + i, 10,
                      to_string(resTime[i]).c_str());
            mvwprintw(scr_Restime_usrRsltPrint, 1 + i, 15, "[ms]");
            wrefresh(scr_Restime_usrRsltPrint);

            // Preparing next turn
            mvwprintw(scr_Restime_Instruct, 1, 1, "Press ENTER KEY to preceed");
            move(1, 0);
            wrefresh(scr_Restime_Instruct);
            getch();
        }

        // After 5 times
        //  ASK the user
        mvwprintw(scr_Restime_Instruct, 1, 1,
                  "Do you want to play more? (y or n)");
        wrefresh(scr_Restime_Instruct);
        std::cin >> selection;
        std::toupper(selection);
    } // Doing game
}
void computeTime(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    ToBeComputed *use;
    long answer, userAnswer;
    string equation;
    clock_t timeStarted = 0, timePressed = 0;
    bool isFailed;

    // Doing game
    while (life > 0) {
        std::cin.ignore();

        //  variable Initialze
        use = new ToBeComputed;
        use->myinit(level);
        answer = use->getAnswer();
        equation = use->getFormula();
        isFailed = false;

        // Print formula
        std::cout << "Calculate " << equation << " in 3 sec" << std::endl;
        std::cout << "Your ans : ";

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

        // if isWrong OR isTimeOut -> life--
        if (isFailed == true) {
            life--;
            std::cout << life << " times remaining" << std::endl;
        }

        level++;
        delete use;
    }

    std::cout << "You Dead!" << std::endl;
}
void computeTime_ncur(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    ToBeComputed *use;
    long answer, userAnswer;
    string equation;
    clock_t timeStarted = 0, timePressed = 0;
    bool isFailed;

    // Initialize window
    initscr();
    WINDOW *scr_Restime_Instruct = newwin(5, 20, 3, 3);
    WINDOW *scr_Restime_usrField = newwin(4, 20, 8, 3);
    mvprintw(0, 0, "You choosed Computation Time!");
    refresh();

    // Doing game
    while (life > 0) {

        // Window setting
        wclear(scr_Restime_Instruct);
        wclear(scr_Restime_usrField);
        box(scr_Restime_Instruct, 0, 0); // added for easy viewing
        box(scr_Restime_usrField, 0, 0); // added for easy viewing
        refresh();
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrField);

        //  variable Initialze
        use = new ToBeComputed;
        use->myinit(level);
        answer = use->getAnswer();
        equation = use->getFormula();
        isFailed = false;

        // Print formula
        mvwprintw(scr_Restime_Instruct, 1, 1, "Calculate in 3sec");
        mvwprintw(scr_Restime_Instruct, 2, 1, "? = ");
        mvwprintw(scr_Restime_Instruct, 2, 5, equation.c_str());
        mvwprintw(scr_Restime_usrField, 1, 1, ">> ");
        refresh();
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrField);

        // COUNTDOWN
        timeStarted = clock();
        std::cin >> userAnswer;

        // CHECK : isWrong?
        if (answer == userAnswer) {
            timePressed = clock();
            mvwprintw(scr_Restime_Instruct, 3, 1, "Correct!");
            refresh();
            wrefresh(scr_Restime_Instruct);
            // CHECK : isTimeOut?
            if (timePressed - timeStarted > 3000) {
                mvwprintw(scr_Restime_Instruct, 3, 1, "Time Out!");
                refresh();
                wrefresh(scr_Restime_Instruct);
                isFailed = true;
            }
        } else {
            timePressed = clock();
            mvwprintw(scr_Restime_Instruct, 3, 1, "Wrong!");
            refresh();
            wrefresh(scr_Restime_Instruct);
            isFailed = true;
        }
        sleep(1);

        // if isWrong OR isTimeOut -> life--
        if (isFailed == true) {
            life--;
            mvwprintw(scr_Restime_Instruct, 3, 1, to_string(life).c_str());
            mvwprintw(scr_Restime_Instruct, 3, 2, " ");
            mvwprintw(scr_Restime_Instruct, 3, 3, "times remaining");
            wrefresh(scr_Restime_Instruct);
        }
        sleep(1);

        level++;
        delete use;
    }
    mvwprintw(scr_Restime_Instruct, 3, 1, "You Dead!");
    wrefresh(scr_Restime_Instruct);
    sleep(1);

    erase();
    delwin(scr_Restime_Instruct);
    delwin(scr_Restime_usrField);
    endwin();
    return;
}

void memoryWhatNum(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    ToBeComputed *use;
    unsigned long answer, userAnswer;

    while (life > 0) {
        std::cin.ignore(); // flush input buffer

        answer = getNum(level);
        // Print number
        std::cout << "REMEMBER " << answer << std::endl;
        sleep(3);

        // after 3sec delete num
        std::cout << "Your ans : ";
        std::cin >> userAnswer;

        // CHECK : isWrong?
        if (answer == userAnswer) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong Answer! life--" << std::endl;
            life--;
        }

        level++;
    }

    std::cout << "You Dead!" << std::endl;
}
void memoryWhatPic(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    unsigned short answerIdx, userAnswer, sizeOfAnsMatrix;
    std::vector<std::vector<bool> /**/> ansMatrix;

    while (life > 0) {
        //  variable Initialze
        PicToBeMemoried opt[4] = {
            PicToBeMemoried(level), PicToBeMemoried(level),
            PicToBeMemoried(level), PicToBeMemoried(level)};

        // Select 1 and that will be answer
        answerIdx = rand() % 3;
        // ansMatrix = opt[answerIdx]->getAnswer();
        //   sizeOfAnsMatrix = opt[answerIdx]->getSizeOfMatrix();

        // Print picture to be memoried - User should remember this
        std::cout << "Remember This: " << std::endl;
        for (int i = 0; i < sizeOfAnsMatrix; i++) {
            for (int j = 0; j < sizeOfAnsMatrix; j++)
                std::cout << ansMatrix[i][j];
            std::cout << std::endl;
        }

        // Print other options
        std::cout << "What is the answer? select 1 : " << std::endl;
        for (int idx = 0; idx < 4; idx++) {
            for (int i = 0; i < sizeOfAnsMatrix; i++) {
                for (int j = 0; j < sizeOfAnsMatrix; j++)
                    //                   std::cout <<
                    //                   opt[idx]->getAnswer()[i][j];
                    std::cout << std::endl;
            }
        }

        // User's selection
        std::cin >> userAnswer;

        // CHECK : isWrong?
        if (answerIdx == userAnswer) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong Answer! life--" << std::endl;
            life--;
        }
    }
    std::cout << "You Dead!" << std::endl;
}
