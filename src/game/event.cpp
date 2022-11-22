
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

void get_event_game(Game &var, Utils &utils)
{
    if (utils.event.type == sf::Event::KeyPressed && utils.event.key.code == sf::Keyboard::Space)
        var.maze.generateNewMaze(WALL_WIDTH, WALL_HEIGHT);
}

}
