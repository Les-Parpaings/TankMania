
#include "game/main.hpp"

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  MANDATORY
//-----------------------------------------------

CellList::CellList()
{
    this->len = 0;
}

CellList::~CellList()
{
}

//-----------------------------------------------
//  UTILS
//-----------------------------------------------

int CellList::size()
{
    return len;
}

void CellList::reset()
{
    this->len = 0;
    this->list.clear();
}

//-----------------------------------------------
//  CREATION
//-----------------------------------------------

void CellList::add(int width, int height, std::vector<int> &horizontal, std::vector<int> &vertical)
{
    int increment_wall_vertical = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            list.push_back(Cell(list.size()));
        }
    }
    len = width * height;

    for (int i = 0; i < len; i++) {

        // DEFINES ADRESS OF ADJACENT CELLS
        if (i / width != 0)
            list[i].up = &list[i - width];

        if (i / width != height - 1)
            list[i].down = &list[i + width];

        if (i % width != 0)
            list[i].left = &list[i - 1];

        if (i % width != width - 1)
            list[i].right = &list[i + 1];

        if (i != 0 && i % width == 0) {
            increment_wall_vertical++;
        }

        list[i].wall_up = &horizontal[i];
        list[i].wall_down = &horizontal[i + width];
        list[i].wall_left = &vertical[i + increment_wall_vertical];
        list[i].wall_right = &vertical[i + 1 + increment_wall_vertical];
    }
}

//-----------------------------------------------
//  SETUP MAZE
//-----------------------------------------------

void CellList::changeIndex(Cell *cell, int value)
{
    int index = cell->index;
    cell->index = value;

    if (cell->up != nullptr && cell->up->index == index)
        changeIndex(cell->up, value);

    if (cell->down != nullptr && cell->down->index == index)
        changeIndex(cell->down, value);

    if (cell->left != nullptr && cell->left->index == index)
        changeIndex(cell->left, value);

    if (cell->right != nullptr && cell->right->index == index)
        changeIndex(cell->right, value);
}

void CellList::destroyWall(int index, int wall)
{
    switch (wall) {
        case UP:
            *list[index].wall_up = false;
            break;
        case DOWN:
            *list[index].wall_down = false;
            break;
        case LEFT:
            *list[index].wall_left = false;
            break;
        case RIGHT:
            *list[index].wall_right = false;
            break;
    }
}

bool CellList::hasSameIndex()
{
    int index = list[0].index;

    for (int i = 1; i < list.size(); i++) {
        if (list[i].index != index) {
            return false;
        }
    }
    return true;
}

//-----------------------------------------------
//  OPERATOR
//-----------------------------------------------

Cell &CellList::operator[](int index)
{
    return list[index];
}

}
