
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

static void create_game(Game &var, Utils &utils)
{
    var.maze.generateNewMaze(WALL_WIDTH, WALL_HEIGHT);
    var.players.create(utils);
}

void create_all(TankMania &var, Utils &utils)
{
    var.part = PART_GAME;

    create_game(var.game, utils);
}

}
