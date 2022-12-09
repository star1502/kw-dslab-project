#include "frontEnd.hpp"
#include "computeTime.hpp"
#include "memoryWhatNum.hpp"
#include "memoryWhatPic.hpp"
#include "responseTime.hpp"

#include <ctime>
#include <iostream>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
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
    time_t timeStarted = 0, timePressed = 0;
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

        // COUNTDOWN Start
        timeStarted = time(NULL);
        std::cin >> userAnswer;

        // CHECK : isWrong?
        if (answer == userAnswer) {
            timePressed = time(NULL);
            std::cout << "Correct!" << std::endl;
        } else {
            timePressed = clock();
            std::cout << "Wrong Answer!" << std::endl;
            isFailed = true;
        }

        // CHECK : isTimeOut?
        if (timePressed - timeStarted > 3) {
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
    time_t timeStarted = 0, timePressed = 0;
    bool isFailed;

    // Initialize window
    initscr();
    WINDOW *scr_Restime_Instruct = newwin(5, 20, 3, 3);
    WINDOW *scr_Restime_usrField = newwin(3, 20, 8, 3);
    mvprintw(0, 0, "You choosed Computation Time!");

    /// Display remaining life
    mvprintw(1, 0, "L : ");
    mvprintw(1, 4, "***");
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

        // Print level
        mvprintw(2, 0, "Level : ");
        mvprintw(2, 8, to_string(level).c_str());
        refresh();

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

        // COUNTDOWN Start// get input from user
        timeStarted = time(NULL);
        wscanw(scr_Restime_usrField, "%d", &userAnswer);

        // CHECK : isWrong?
        int checher = answer - userAnswer;
        if (checher == 0) {
            timePressed = time(NULL);
            mvwprintw(scr_Restime_Instruct, 3, 1, "Correct!");
            refresh();
            wrefresh(scr_Restime_Instruct);
            // CHECK : isTimeOut?
            if (timePressed - timeStarted > 3) {
                mvwprintw(scr_Restime_Instruct, 3, 1, "Time Out!");
                refresh();
                wrefresh(scr_Restime_Instruct);
                isFailed = true;
            }
        } else {
            mvwprintw(scr_Restime_Instruct, 3, 1, "Wrong!");
            refresh();
            wrefresh(scr_Restime_Instruct);
            isFailed = true;
        }
        sleep(1);

        // if isWrong OR isTimeOut -> life--
        if (isFailed == true) {
            life--;
            mvdelch(1, 4 + life);
            mvwprintw(scr_Restime_Instruct, 3, 1, to_string(life).c_str());
            mvwprintw(scr_Restime_Instruct, 3, 2, " ");
            mvwprintw(scr_Restime_Instruct, 3, 3, "times remaining");
            wrefresh(scr_Restime_Instruct);
        }
        sleep(1);

        level++;
        delete use;
    }
    mvwprintw(scr_Restime_Instruct, 3, 1, "You Dead!       ");
    wrefresh(scr_Restime_Instruct);
    sleep(1);

    erase();
    delwin(scr_Restime_Instruct);
    delwin(scr_Restime_usrField);
    endwin();
    return;
}

void memoryWhatNum_ncur(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    ToBeComputed *use;
    unsigned long answer, userAnswer;

    // Initialize window
    initscr();
    WINDOW *scr_Restime_Instruct = newwin(4, 20, 3, 3);
    WINDOW *scr_Restime_usrField = newwin(3, 20, 8, 3);
    mvprintw(0, 0, "You choosed Memory Number!");
    refresh();

    /// Display remaining life
    mvprintw(1, 0, "L : ");
    mvprintw(1, 4, "***");

    while (life > 0) {
        // Window setting
        wclear(scr_Restime_Instruct);
        wclear(scr_Restime_usrField);
        box(scr_Restime_Instruct, 0, 0); // added for easy viewing
        box(scr_Restime_usrField, 0, 0); // added for easy viewing
        refresh();
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrField);

        // Print level
        mvprintw(2, 0, "Level : ");
        mvprintw(2, 8, to_string(level).c_str());
        refresh();

        // Ready
        mvwprintw(scr_Restime_Instruct, 2, 1, "Press Enter");
        wrefresh(scr_Restime_Instruct);

        std::cin.ignore(); // flush input buffer
        fflush(stdin);

        // Get randomly generated num
        answer = getNum(level);

        // Print number and 3sec wait
        mvwprintw(scr_Restime_Instruct, 1, 1, "REMEMBER:");
        mvwprintw(scr_Restime_Instruct, 2, 1, "%lld          ", answer);
        mvwprintw(scr_Restime_usrField, 1, 1, "");
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrField);
        sleep(3);

        // after 3sec delete num
        mvwprintw(scr_Restime_Instruct, 2, 1, "What?:       ");
        wrefresh(scr_Restime_Instruct);
        mvwprintw(scr_Restime_usrField, 1, 1, ">> ");
        wrefresh(scr_Restime_usrField);

        // get input from user
        wscanw(scr_Restime_usrField, "%llu", &userAnswer);

        // CHECK : isWrong?
        if (answer == userAnswer) {
            mvwprintw(scr_Restime_Instruct, 2, 1, "Correct!");
            refresh();
            wrefresh(scr_Restime_Instruct);
        } else {
            mvwprintw(scr_Restime_Instruct, 2, 1, "Wrong!");
            refresh();
            wrefresh(scr_Restime_Instruct);
            sleep(1);

            life--;
            mvdelch(1, 4 + life);
            mvwprintw(scr_Restime_Instruct, 2, 1, to_string(life).c_str());
            mvwprintw(scr_Restime_Instruct, 2, 2, " ");
            mvwprintw(scr_Restime_Instruct, 2, 3, "times remaining");
            wrefresh(scr_Restime_Instruct);
        }
        sleep(1);
        mvwprintw(scr_Restime_usrField, 1, 1, "    ");
        wrefresh(scr_Restime_usrField);

        move(2, 0);
        clrtoeol();
        level++;
    }

    mvwprintw(scr_Restime_Instruct, 2, 1, "You Dead!         ");
    wrefresh(scr_Restime_Instruct);
    sleep(1);

    erase();
    delwin(scr_Restime_Instruct);
    delwin(scr_Restime_usrField);
    endwin();
}
void memoryWhatPic_ncur(void) {
    int life = 3; // Allow user to be wrong UP TO 3 TIMES
    unsigned int level = 1;

    // variable declare
    short answerIdx, userAnswer, sizeOfAnsMatrix;
    short power2;
    std::vector<short> ansMatrix;
    std::vector<short> opt[4];

    // Initialize window
    initscr();
    WINDOW *scr_Restime_Instruct = newwin(11, 55, 3, 3);
    WINDOW *scr_Restime_usrField = newwin(3, 15, 15, 3);
    mvprintw(0, 0, "You choosed Memory Picture!");
    refresh();

    /// Display remaining life
    mvprintw(1, 0, "L : ");
    mvprintw(1, 4, "***");

    while (life > 0) {
        // Window setting
        wclear(scr_Restime_Instruct);
        wclear(scr_Restime_usrField);
        box(scr_Restime_Instruct, 0, 0); // added for easy viewing
        box(scr_Restime_usrField, 0, 0); // added for easy viewing
        refresh();
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrField);

        // Print level
        mvprintw(2, 0, "Level : ");
        mvprintw(2, 8, to_string(level).c_str());
        refresh();

        // Matrix options Initialze
        srand(time(NULL));
        sizeOfAnsMatrix = getSizeOfMatrix(level);
        power2 = sizeOfAnsMatrix * sizeOfAnsMatrix;
        for (int i = 0; i < 4; i++)
            opt[i].resize(0);

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < power2; j++)
                opt[i].push_back(rand() % 2);

        // Select 1 and that will be answer
        answerIdx = rand() % 4;
        ansMatrix = opt[answerIdx];

        // Ready
        mvwprintw(scr_Restime_Instruct, 1, 1, "Press Enter To Cont");
        wrefresh(scr_Restime_Instruct);

        std::cin.ignore(); // flush input buffer
        fflush(stdin);

        // Print picture to be memoried
        // User should remember this
        int yptr = 2;
        int xptr = 1;
        mvwprintw(scr_Restime_Instruct, 1, 1, "REMEMBER:                ");
        for (int i = 0; i < power2; i++) {
            if (i % sizeOfAnsMatrix == 0) {
                yptr++;
                xptr = 1;
            }
            mvwprintw(scr_Restime_Instruct, yptr, xptr++, "%d",
                      ansMatrix.at(i));
        }
        wrefresh(scr_Restime_Instruct);
        sleep(3);

        // after 3sec delete pic
        wclear(scr_Restime_Instruct);
        box(scr_Restime_Instruct, 0, 0); // added for easy viewing
        mvwprintw(scr_Restime_Instruct, 1, 1, "What? ");
        refresh();
        mvwprintw(scr_Restime_usrField, 1, 1, ">> ");
        wrefresh(scr_Restime_Instruct);
        wrefresh(scr_Restime_usrField);

        // Print other options
        yptr = 2;
        xptr = 1;
        int xptr_cur = xptr;
        for (int idx = 0; idx < 4; idx++) {
            mvwprintw(scr_Restime_Instruct, yptr, xptr_cur, "OPT");
            mvwprintw(scr_Restime_Instruct, yptr, xptr_cur + 3,
                      to_string(idx).c_str());
            mvwprintw(scr_Restime_Instruct, yptr, xptr_cur + 4, " :");
            for (int i = 0; i < power2; i++) {
                if (i % sizeOfAnsMatrix == 0) {
                    yptr++;
                    xptr = xptr_cur;
                }
                mvwprintw(scr_Restime_Instruct, yptr, xptr++, "%d",
                          opt[idx].at(i));
            }
            xptr = 11 + 9 * idx;
            xptr_cur = xptr;
            yptr = 2;
        }
        wrefresh(scr_Restime_Instruct);

        // get input from user
        wscanw(scr_Restime_usrField, "%d", &userAnswer);

        // CHECK : isWrong?
        int checher = userAnswer - userAnswer;
        if (checher == 0) {
            mvwprintw(scr_Restime_Instruct, 9, 1, "Correct!");
            refresh();
            wrefresh(scr_Restime_Instruct);
        } else {
            mvwprintw(scr_Restime_Instruct, 9, 1, "Wrong!");
            refresh();
            wrefresh(scr_Restime_Instruct);
            sleep(1);

            life--;
            mvdelch(1, 4 + life);
            mvwprintw(scr_Restime_Instruct, 9, 1, to_string(life).c_str());
            mvwprintw(scr_Restime_Instruct, 9, 2, " ");
            mvwprintw(scr_Restime_Instruct, 9, 3, "times remaining");
            wrefresh(scr_Restime_Instruct);
        }
        sleep(1);
        mvwprintw(scr_Restime_usrField, 1, 1, "    ");
        wrefresh(scr_Restime_usrField);

        move(2, 0);
        clrtoeol();
        level++;
    }
    mvwprintw(scr_Restime_Instruct, 9, 1, "You Dead!         ");
    wrefresh(scr_Restime_Instruct);
    sleep(1);

    erase();
    delwin(scr_Restime_Instruct);
    delwin(scr_Restime_usrField);
    endwin();
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
    unsigned short power2;
    std::vector<bool> ansMatrix;
    std::vector<bool> opt[4];
    std::cout << "Memory Picture: " << std::endl;

    while (life > 0) {
        //  Matrix options Initialze
        srand(time(NULL));
        sizeOfAnsMatrix = getSizeOfMatrix(level);
        power2 = sizeOfAnsMatrix * sizeOfAnsMatrix;
        for (int i = 0; i < 4; i++)
            opt[i].resize(0);

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < power2; j++)
                opt[i].push_back(rand() % 2);

        // Select 1 and that will be answer
        answerIdx = rand() % 4;
        ansMatrix = opt[answerIdx];

        // Print picture to be memoried
        // User should remember this
        std::cout << "Remember This: " << std::endl;
        for (int i = 0; i < power2; i++) {
            if (i % sizeOfAnsMatrix == 0)
                std::cout << " ";
            std::cout << ansMatrix.at(i);
        }
        std::cout << std::endl;

        // Print other options
        std::cout << "What is the answer? select 1 : " << std::endl;
        for (int idx = 0; idx < 4; idx++) {
            std::cout << idx << " :";
            for (int i = 0; i < power2; i++) {
                if (i % sizeOfAnsMatrix == 0)
                    std::cout << " ";
                std::cout << opt[idx].at(i);
            }
            std::cout << "\n";
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
