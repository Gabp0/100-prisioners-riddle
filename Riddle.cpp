#include "Riddle.h"
#include <random>
#include <iostream>
#include <vector>

Riddle::Riddle()
{
    this->boxes.reserve(BOX_MAX + 1);
    this->prisioners.reserve(BOX_MAX + 1);

    std::fill_n(this->boxes.begin(), BOX_MAX + 1, 0);
    std::fill_n(this->prisioners.begin(), BOX_MAX + 1, false);

    this->fillBoxes();
}

Riddle::~Riddle()
{
}

void Riddle::fillBoxes()
{
    for (size_t i = BOX_MIN; i <= BOX_MAX; i++)
    {
        int r = rand() % (BOX_MAX - BOX_MIN + 1) + BOX_MIN;

        while (this->boxes[r] != 0)
        {
            r = rand() % (BOX_MAX - BOX_MIN + 1) + BOX_MIN;
        }

        this->boxes[r] = i;
    }
}

void Riddle::rearrange()
{
    std::fill_n(this->boxes.begin(), BOX_MAX + 1, 0);
    std::fill_n(this->prisioners.begin(), BOX_MAX + 1, false);
    this->fillBoxes();
}

void Riddle::listBoxContents()
{
    for (size_t i = BOX_MIN; i <= BOX_MAX; i++)
    {
        std::cout << i << ": " << this->boxes[i] << std::endl;
    }
}

void Riddle::listPrisioners()
{
    for (size_t i = BOX_MIN; i <= BOX_MAX; i++)
    {
        std::cout << i << ": " << this->prisioners[i] << std::endl;
    }
}

void Riddle::solveRandom()
{
    std::vector<bool> openedBoxes;
    openedBoxes.reserve(BOX_MAX + 1);

    for (size_t i = BOX_MIN; i <= BOX_MAX; i++)
    {
        std::fill(openedBoxes.begin(), openedBoxes.end(), false);
        for (size_t j = 0; j < 50; j++)
        {
            int box = rand() % (BOX_MAX - BOX_MIN + 1) + BOX_MIN;
            while (openedBoxes[box])
            {
                box = rand() % (BOX_MAX - BOX_MIN + 1) + BOX_MIN;
            }

            if (this->boxes[box] == i)
            {
                this->prisioners[i] = true;
                break;
            }
        }
    }
}

bool Riddle::checkFree()
{
    for (size_t i = BOX_MIN; i <= BOX_MAX; i++)
    {
        if (!this->prisioners[i])
            return false;
    }
    return true;
}

void Riddle::solveLoop()
{
    for (size_t i = BOX_MIN; i <= BOX_MAX; i++)
    {
        int nextBox = i;
        for (size_t j = 0; j < 50; j++)
        {
            if (this->boxes[nextBox] == i)
            {
                this->prisioners[i] = true;
                break;
            }

            nextBox = this->boxes[nextBox];
        }
    }
}