#include "memoryWhatPic.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
/*
// Default constructor
PicToBeMemoried::PicToBeMemoried(void) {}

void PicToBeMemoried::init(unsigned int level) {
    sizeOfMatrix = deterSizeOfMatrix(level);
    numOfFilled = deterNumOfFilled();
    initMatrix();
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
    unsigned short power2 = sizeOfMatrix * sizeOfMatrix;
    // srand(time(NULL));
    return (rand() % (power2 / 2)) + power2 / 4;
}

// Initialize Matrix
void PicToBeMemoried::initMatrix(void) {
    matrix.resize(sizeOfMatrix * sizeOfMatrix);

    // Initialzed to same as :
    // bool matrix[numOfFilled]={false, }
    for (int i = 0; i < sizeOfMatrix * sizeOfMatrix; i++) {
        matrix.push_back(false);
    }
}

// Make pictures will be Printed based on value [numOfFilled]
void PicToBeMemoried::makeMatrix(void) {
    unsigned short temp = numOfFilled;

    // Fill in the blanks as many as numOfFilled value
    // false -> BLANK square
    // true -> FILLED square
    while (temp > 0) {
        for (int i = 0; i < sizeOfMatrix * sizeOfMatrix; i++) {
            if (matrix[i] == false) {
                matrix[i] = true;
                temp--;
            }
        }
    }
}
*/

unsigned short getSizeOfMatrix(unsigned int level) {
    unsigned short sizeOfMatrix;

    switch (level) {
    case 1:
    case 2:
        sizeOfMatrix = 3;
        break;
    case 3:
    case 4:
        sizeOfMatrix = 4;
        break;
    case 5:
    case 6:
        sizeOfMatrix = 5;
        break;
    default:
        sizeOfMatrix = 6;
        break;
    }
    return sizeOfMatrix;
}

std::vector<bool> getOption(unsigned int level) {
    unsigned short sizeOfMatrix;
    unsigned short numOfFilled;

    switch (level) {
    case 1:
    case 2:
        sizeOfMatrix = 3;
        break;
    case 3:
    case 4:
        sizeOfMatrix = 4;
        break;
    case 5:
    case 6:
        sizeOfMatrix = 5;
        break;
    default:
        sizeOfMatrix = 6;
        break;
    }
    //-------------------

    unsigned short power2 = sizeOfMatrix * sizeOfMatrix;
    srand(time(NULL));
    numOfFilled = (rand() % (power2 / 2)) + power2 / 4;

    //-------------------

    std::vector<bool> matrix(power2, false);

    //-------------------
    unsigned short temp = numOfFilled;

    // Fill in the blanks as many as numOfFilled value
    // false -> BLANK square
    // true -> FILLED square
    while (temp > 0) {
        for (int i = 0; i < power2; i++) {
            if (matrix[i] == false) {
                matrix[i] = true;
                temp--;
            }
        }
    }
    return matrix;
}
