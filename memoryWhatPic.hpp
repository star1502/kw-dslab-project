#include <vector>

class PicToBeMemoried {
  public:
    PicToBeMemoried(unsigned int level);
    std::vector<std::vector<bool>> getAnswer(void) { return matrix; };

  private:
    // Determine size of width, height
    unsigned short deterSizeOfMatrix(unsigned int level);
    // Determine the num of colored square
    unsigned short deterNumOfFilled(void);
    // Make pictures will be Printed based on value [numOfFilled]
    void makeMatrix(void);

    unsigned short sizeOfMatrix;
    unsigned short numOfFilled;
    std::vector<std::vector<bool>> matrix;
};
