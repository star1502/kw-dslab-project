#include "memoryWhatNum.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns the number to be remembered
unsigned long getNum(unsigned int level) {
    srand(time(NULL));
    unsigned long retVal = rand() * rand(); // This variable will be returned
    retVal = retVal % numOfDigits(level);
    return retVal;
}

// Returns the number of digits
// Max digit : 10
unsigned long numOfDigits(unsigned int level) {
    if (level > 11)
        level = 10;
    return (unsigned long)pow(10, level);
}
