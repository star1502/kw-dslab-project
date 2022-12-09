#include "computeTime.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>

// Default constructor : Determine the FORMULA - ADD/SUB/MUL
ToBeComputed::ToBeComputed(void) {}

// Default constructor : Determine the FORMULA - ADD/SUB/MUL
void ToBeComputed::myinit(unsigned int level) {
    this->level = level;
    operation = deterOperation();
    operand1 = deterOperand();
    operand2 = deterOperand();
    if (operand1 < operand2) {
        unsigned long temp = operand1;
        operand1 = operand2;
        operand2 = temp;
    }
    answer = computeAnswer();
}

// Return Operator in '+' or '-' or '*'
char ToBeComputed::getOperation(void) {
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

// Return calculation Formula in string type
std::string ToBeComputed::getFormula(void) {
    std::string retVal;
    retVal =
        std::to_string(operand1) + getOperation() + std::to_string(operand2);
    return retVal;
}

// Determine the type of OPERATION : ADD/SUB/MUL
char ToBeComputed::deterOperation(void) {
    // srand(time(NULL));
    return (rand() % 3);
    // 0-> ADD
    // 1-> SUB
    // 2-> MUL
}

// Determine the OPERAND - level and the type of operator will be considered
unsigned long ToBeComputed::deterOperand(void) {
    int garbage;
    // srand(time(NULL));
    unsigned long retVal = rand(); // This variable will be returned

    switch (this->operation) {
    case 0: //+
    case 1: //-
        if (this->level < 4)
            retVal = 1 + retVal % 9;
        else if (this->level < 7)
            retVal = 9 + retVal % 20;
        else if (this->level < 10)
            retVal = 14 + retVal % 30;
        else
            retVal = 20 + retVal % 50;
        return retVal;
        break;
    case 2: //*
        if (this->level < 4)
            retVal = retVal % 10;
        else if (this->level < 8)
            retVal = 4 + retVal % 10;
        else
            retVal = 8 + retVal % 6;
        return retVal;
        break;
    default:
        return 999;
        break;
    }
}

long ToBeComputed::computeAnswer(void) {
    switch (this->operation) {
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
