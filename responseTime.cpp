#include "responseTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function returns in Microseconds
// 1 us == 10^-3ms == 10^-6 s
// return range : 3 000 000 ~ 5 499 000
unsigned long waitHowMuchTime(void) {
    unsigned long retVal = 0; // This variable will be returned

    srand(time(NULL));
    retVal = rand() % 2500; // 0 ~ 2.5 ms
    retVal += 3000;         // 3 ~ 5.5 ms
    return retVal * 1000;   // 3 ~ 5.5 s
}
