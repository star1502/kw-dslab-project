#include "memoryWhatNum.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long whatNum_getNum(unsigned int level) {
    srand(time(NULL));
    unsigned long retVal = rand() * rand(); // This variable will be returned
    retVal /= numOfDigits(level);
    return retVal;
}

unsigned long numOfDigits(unsigned int level) {
    if (level > 13)
        level = 12;
    return (unsigned long)pow(10, level);
}
