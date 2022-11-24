#include "computeTime.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

// Default constructor : Determine the FORMULA - ADD/SUB/MUL
ToBeComputed::ToBeComputed(unsigned int level) {
    operation = deterOperation();
    operand1 = deterOperand(level);
    operand2 = deterOperand(level);
    answer = computeAnswer();
}

// Return Operator in '+' or '-' or '*'
unsigned long ToBeComputed::computeAnswer(void) {
    switch (operation) {
    case 0: //+
        return '+';
    case 1: //-
        return '-';
    case 2: //*
        return '*';
    default:
        break;
    }
}

// Determine the type of OPERATION : ADD/SUB/MUL
char ToBeComputed::deterOperation(void) {
    srand(time(NULL));
    return (rand() % 3);
    // 0-> ADD
    // 1-> SUB
    // 2-> MUL
}

// Determine the OPERAND - level and the type of operator will be considered
unsigned long ToBeComputed::deterOperand(unsigned int level) {
    srand(time(NULL));
    unsigned long retVal = rand() * rand(); // This variable will be returned

    switch (operation) {
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
            retVal = 1 + retVal % 12;
        return retVal;
        break;
    default:
        return 5;
        break;
    }
}

unsigned long ToBeComputed::computeAnswer(void) {
    switch (operation) {
    case 0: //+
        return (operand1 + operand2);
    case 1: //-
        return (operand1 - operand2);
    case 2: //*
        return (operand1 * operand2);
    default:
        break;
    }
}
