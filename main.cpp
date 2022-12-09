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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // PRINT List of the games
        std::cout << "Usage : " << argv[0] << " [num]" << std::endl;
        std::cout << "Choose the game you want to play :" << std::endl
                  << "1. React Fast " << std::endl
                  << "2. Do Calculate Fast " << std::endl
                  << "3. Memory the Number" << std::endl
                  << "4. Memory the Picture" << std::endl;
        exit(-1);
    }

    // Randon seed initialize
    srand(time(NULL));
    unsigned short selection = atoi(argv[1]);

    // exception check
    if (selection < 1 || selection > 4) {
        std::cout << "WRONG NUM!" << std::endl;
        exit(-1);
    }

    if (selection == 1)
        responseTime();
    else if (selection == 2)
        computeTime_ncur();
    else if (selection == 3)
        memoryWhatNum_ncur();
    else if (selection == 4)
        memoryWhatPic_ncur();

    return 0;
}
