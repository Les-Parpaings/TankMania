
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

static void draw_game(Game &var, Utils &utils)
{
    #if COLLISION_TEST == 0
    var.maze.draw(utils.window);
    #endif
    var.players.draw(utils.window);
}

void draw(TankMania &var, Utils &utils)
{
    utils.clear(sf::Color(64, 64, 64));

    switch (var.part) {
        case PART_MENU:
            break;
        case PART_GAME:
            draw_game(var.game, utils);
            break;
    }

    utils.draw();
}

}
