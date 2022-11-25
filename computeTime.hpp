class ToBeComputed {
  public:
    // Default constructor : Determine the FORMULA - ADD/SUB/MUL
    ToBeComputed(unsigned int level);
    unsigned long getOperand1(void) { return operand1; }
    unsigned long getOperand2(void) { return operand2; }
    char getOperation(void);
    unsigned long getAnswer(void) { return answer; }
    std::string getFormula(void);

  private:
    char deterOperation(void); // Determine the type of OPERATION : ADD/SUB/MUL
    unsigned long
    deterOperand(unsigned int level); // Determine the OPERAND - level and the
                                      // type of operator will be considered
    unsigned long computeAnswer();

    unsigned long operand1;
    unsigned long operand2;
    char operation;
    unsigned long answer;
};
