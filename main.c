#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include "computeTime.h"
#include "memoryWhatNum.h"
#include "memoryWhatPic.h"
#include "myVector.h"
#include "responseTime.h"

void mySigHandler(int signum) {}

int main(void) {
    signal(SIGINT, mySigHandler);
    return 0;
}
