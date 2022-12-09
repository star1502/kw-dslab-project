#include <vector>
/*
class PicToBeMemoried {
  public:
    PicToBeMemoried(void);
    void init(unsigned int level);
    unsigned short getSizeOfMatrix(void) { return sizeOfMatrix; }
    std::vector<bool> getAnswer(void) { return matrix; };

  private:
    // Determine size of width, height
    unsigned short deterSizeOfMatrix(unsigned int level);
    // Determine the num of colored square
    unsigned short deterNumOfFilled(void);
    // Initialize Matrix
    void initMatrix(void);
    // Make pictures will be Printed based on value [numOfFilled]
    void makeMatrix(void);

    unsigned short sizeOfMatrix;
    unsigned short numOfFilled;
    std::vector<bool> matrix;
};
*/

unsigned short getSizeOfMatrix(unsigned int level);
std::vector<bool> getOption(unsigned int level);
