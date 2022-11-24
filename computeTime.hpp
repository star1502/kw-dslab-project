class ToBeComputed {
  public:
    ToBeComputed(unsigned int level);
    unsigned long getOperand1(void) { return operand1; }
    unsigned long getOperand2(void) { return operand2; }
    char getOperation();
    unsigned long getAnswer(void) { return answer; }

  private:
    char deterOperation(void);
    unsigned long deterOperand(unsigned int level);
    unsigned long computeAnswer();

    unsigned long operand1;
    unsigned long operand2;
    char operation;
    unsigned long answer;
};
