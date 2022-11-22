
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

static void draw_game(Game &var, Utils &utils)
{
    var.maze.draw(utils.window);
}

void draw(TankMania &var, Utils &utils)
{
    utils.clear(sf::Color::Black);

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
