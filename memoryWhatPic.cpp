#include "memoryWhatPic.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **whatPic_makePic(unsigned int level) {
    // Get size of width, height
    unsigned short sizeOfRowCol = whatPic_getsizeOfRowCol(level);
    // bool type 2D array - it will be used max 6*6
    char picture[6][6] = {
        '0',
    };

    // determine the num of colored square
    unsigned short numOfFilled;
    srand(time(NULL));
    numOfFilled = rand() % (sizeOfRowCol * (sizeOfRowCol - 1));

    for (int i = 0; i < sizeOfRowCol; i++) {
        for (int j = 0; i < sizeOfRowCol; i++) {
        }
    }
}

unsigned short whatPic_getsizeOfRowCol(unsigned int level) {
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
