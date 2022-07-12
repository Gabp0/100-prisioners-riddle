#include <iostream>
#include "Riddle.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Riddle pr;

    pr.listBoxContents();
    pr.listPrisioners();
    pr.solveRandom();
    pr.listPrisioners();
}
