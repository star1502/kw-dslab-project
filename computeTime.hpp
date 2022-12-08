#include <string>

class ToBeComputed {
  public:
    ToBeComputed(void);

    // Default constructor : Determine the FORMULA - ADD/SUB/MUL
    void myinit(unsigned int level);
    unsigned long getOperand1(void) { return operand1; }
    unsigned long getOperand2(void) { return operand2; }
    char getOperation(void);
    unsigned long getAnswer(void) { return answer; }
    std::string getFormula(void);

  private:
    char deterOperation(void); // Determine the type of OPERATION : ADD/SUB/MUL
    unsigned long deterOperand(void); // Determine the OPERAND - level and the
                                      // type of operator will be considered
    long computeAnswer(void);

    unsigned long operand1;
    unsigned long operand2;
    char operation;
    long answer;
    unsigned int level;
};
