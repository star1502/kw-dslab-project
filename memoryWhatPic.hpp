class PicToBeMemoried {
  public:
    PicToBeMemoried(unsigned int level);
    std::vector<std::vector<bool>> getAnswer(void) { return matrix; };

  private:
    unsigned short deterSizeOfMatrix(unsigned int level);
    unsigned short deterNumOfFilled(void);
    void makeMatrix(void);

    unsigned short sizeOfMatrix;
    unsigned short nunOfFilled;
    std::vector<std::vector<bool>> matrix;
};
