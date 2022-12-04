
#include "game/main.hpp"

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  MANDATORY
//-----------------------------------------------

Cell::Cell(int id)
{
    this->id = id;
    this->index = id;

    this->up    = nullptr;
    this->down  = nullptr;
    this->left  = nullptr;
    this->right = nullptr;

    this->wall_up    = nullptr;
    this->wall_down  = nullptr;
    this->wall_left  = nullptr;
    this->wall_right = nullptr;
}

//-----------------------------------------------
//  OPERATOR
//-----------------------------------------------

Cell *Cell::operator[](int index)
{
    switch (index) {
        case UP:
            return up;
        case DOWN:
            return down;
        case LEFT:
            return left;
        case RIGHT:
            return right;
        default:
            return nullptr;
    }
}

}
