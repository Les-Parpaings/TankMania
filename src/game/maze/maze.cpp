
#include "game/main.hpp"
#include <algorithm>

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  MANDATORY
//-----------------------------------------------

Maze::Maze()
{
    this->width = 0;
    this->height = 0;
}

Maze::~Maze()
{
}

//-----------------------------------------------
//  UTILS
//-----------------------------------------------

void Maze::reset()
{
    this->cells.reset();

    this->width = 0;
    this->height = 0;

    this->horizontal.clear();
    this->vertical.clear();
    this->random.clear();

    this->walls.clear();
}

sf::Vector2f Maze::getSize()
{
    return sf::Vector2f(width, height);
}

//-----------------------------------------------
//  GENERATION
//-----------------------------------------------

bool hasCell(std::vector<int> &random, int index)
{
    for (auto &it : random) {
        if (it == index) {
            return true;
        }
    }
    return false;
}

void Maze::generateNewRandom()
{
    random.clear();

    for (int i = 0; i < cells.size(); i++) {
        if (hasCell(random, cells[i].index))
            continue;
        random.push_back(cells[i].id);
    }

    std::random_shuffle(random.begin(), random.end());
}

void Maze::generateNewMaze(int x, int y)
{
    reset();

    this->width = x;
    this->height = y;

    this->horizontal = std::vector((height + 1) * width, 1);
    this->vertical = std::vector((width + 1) * height, 1);

    cells.add(width, height, horizontal, vertical);

    while (!cells.hasSameIndex()) {
        generateNewRandom();
        for (int index = 0; index < random.size(); index++) {

            int index_next = Random::getRandom(4);
            int index_cell = random[index];

            for (int i = 0; i < 4; i++) {
                if (cells[index_cell][index_next] != nullptr && cells[index_cell].index != cells[index_cell][index_next]->index) {
                    cells.changeIndex(cells[index_cell][index_next], cells[index_cell].index);
                    cells.destroyWall(index_cell, index_next);
                    break;
                } else {
                    index_next++;
                    if (index_next >= 4) {
                        index_next = 0;
                    }
                }
            }
        }
    }

    generateGraphics();
}

}
