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

int main(void) {
    // Randon seed initialize
    srand(time(NULL));

    std::cout << "Welcome to HUMAN BENCHMARK!" << std::endl;
    computeTime_ncur();

    while (1) {

        // PRINT List of the games
        std::cout << "Choose the game you want to play (q to exit)" << std::endl
                  << "1. Measure your Reaction Time " << std::endl
                  << "2. Calculation time" << std::endl
                  << "3. Memory the number" << std::endl
                  << "4. Memory the picture" << std::endl
                  << "Your Choose : ";

        // Get input from user
        std::cin.ignore();
        unsigned short selection;
        std::cin >> selection;

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
            break;
        }
    }

    return 0;
}
