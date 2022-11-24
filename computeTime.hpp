

// Determine the FORMULA : ADD/SUB/MUL
struct formula computeWhat(unsigned int level);

// Determine the type of OPERATION : ADD/SUB/MUL
char deterOperation(void);
// Determine the OPERAND - level and the type of operator will be considered
unsigned long deterOperand(unsigned int level, char operatorType);
