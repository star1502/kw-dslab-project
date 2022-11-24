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
    int temp = rand() % 3;
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
unsigned long deterOperand(unsigned int level, char operatorType) {
    srand(time(NULL));
    unsigned long retVal = rand() * rand(); // This variable will be returned

    switch (operatorType) {
    case '+':
    case '-':
        if (level < 5)
            retVal = 1 + retVal % 9;
        else if (level < 11)
            retVal = 1 + retVal % 30;
        else
            retVal = 1 + retVal % 100;
        return retVal;
        break;
    case '*':
        if (level < 8)
            retVal = retVal % 10;
        else
            retVal = 1 + retVal % 14;
        return retVal;
        break;
    default:
        return 5;
        break;
    }
}
