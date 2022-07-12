#include <vector>
#define BOX_MAX 99
#define BOX_MIN 0

class Riddle
{
private:
    std::vector<int> boxes;
    std::vector<bool> prisioners;

    void fillBoxes();

public:
    Riddle();
    ~Riddle();
    void rearrange();
    void listBoxContents();
    void listPrisioners();
    void solveRandom();
    void solveLoop();
    bool checkFree();
};
