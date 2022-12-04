
#include "game/main.hpp"

using namespace utils;
namespace Tank {

void Game::draw(Utils &utils)
{
    utils.clear(sf::Color::White);

    maze.draw(utils.window);
    for (auto &it : powerups)
        it.draw(utils.window);
    for (auto &it : players)
        it.draw(utils.window);
    for (auto &it : projectile)
        it.draw(utils.window);

    utils.draw();
}

}
