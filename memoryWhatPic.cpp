#include "memoryWhatPic.hpp"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

// constructor
PicToBeMemoried::PicToBeMemoried(unsigned int level) {
    sizeOfMatrix = deterSizeOfMatrix(level);
    numOfFilled = deterNumOfFilled();
    matrix.resize(sizeOfMatrix);
    makeMatrix();
}

// Determine size of width, height
unsigned short PicToBeMemoried::deterSizeOfMatrix(unsigned int level) {
    switch (level) {
    case 1:
    case 2:
    case 3:
        return 3;
        break;
    case 4:
    case 5:
        return 4;
        break;
    case 6:
    case 7:
        return 5;
        break;
    default:
        return 6;
        break;
    }
}

// determine the num of colored square
unsigned short PicToBeMemoried::deterNumOfFilled(void) {
    srand(time(NULL));
    return rand() % (sizeOfMatrix * (sizeOfMatrix - 1));
}

void PicToBeMemoried::makeMatrix(void) {
    // Initialzed to same as :
    // bool temp[numOfFilled][numOfFilled]={false, }
    vector<vector<bool>> temp(numOfFilled, vector<bool>(numOfFilled, false));

    unsigned short temp = numOfFilled;
    while (numOfFilled > 0) {
    }
}
