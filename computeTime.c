#include "computeTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct formula {
    unsigned long operand1;
    unsigned long operand2;
    char operator;
};

// Determine the FORMULA : ADD/SUB/MUL
struct formula computeWhat(unsigned int level) {
    struct formula retForm;

    retForm.operator= deterOperation();
    retForm.operand1 = deterOperand(level, retForm.operator);
    retForm.operand2 = deterOperand(level, retForm.operator);

    return retForm;
}

// Determine the type of OPERATION : ADD/SUB/MUL
char deterOperation(void) {
    srand(time(NULL));
    int temp = rand() / 3;
    switch (temp) {
    case 0:
        return '+';
    case 1:
        return '-';
    case 2:
        return '*';
    default:
        break;
    }
}

// Determine the OPERAND - level and the type of operator will be considered
unsigned long deterOperand(unsigned int level, char operatorType) {}
