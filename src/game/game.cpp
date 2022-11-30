
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

void do_game(TankMania &var, Utils &utils)
{
    var.game.players.doMovement(var.game.maze.getGraphics());
}

}
