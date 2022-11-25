#include "memoryWhatPic.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

// Default constructor
PicToBeMemoried::PicToBeMemoried(unsigned int level) {
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
    srand(time(NULL));
    return (rand() % (power2 / 2)) + power2 / 4;
}

// Initialize Matrix
void PicToBeMemoried::initMatrix(void) {
    //
    matrix.resize(sizeOfMatrix);

    // vector to be pushed to Matrix
    // same as bool v1={false, }
    std::vector<bool> v1(sizeOfMatrix, false);

    // Initialzed to same as :
    // bool matrix[numOfFilled][numOfFilled]={false, }
    for (int i = 0; i < sizeOfMatrix; i++) {
        matrix.push_back(v1);
    }
}

// Make pictures will be Printed based on value [numOfFilled]
void PicToBeMemoried::makeMatrix(void) {
    unsigned short temp = numOfFilled;

    // Fill in the blanks as many as numOfFilled value
    // false -> BLANK square
    // true -> FILLED square
    while (temp > 0) {
        for (int i = 0; i < sizeOfMatrix; i++) {
            for (int j = 0; j < sizeOfMatrix; j++) {
                if (matrix[i][j] == false) {
                    matrix[i][j] = true;
                    temp--;
                }
            }
        }
    }
}
