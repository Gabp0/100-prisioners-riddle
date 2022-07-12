#include <iostream>
#include "Riddle.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Riddle pr;

    int randomSolved = 0, loopSolved = 0;

    for (size_t i = 0; i < 1000; i++)
    {
        pr.rearrange();
        pr.solveRandom();
        if (pr.checkFree())
            randomSolved++;

        pr.rearrange();
        pr.solveLoop();
        if (pr.checkFree())
            loopSolved++;
    }

    cout << "Loop: " << loopSolved << ", Random: " << randomSolved << endl;
}
