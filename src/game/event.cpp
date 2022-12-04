
#include "game/main.hpp"

using namespace utils;
namespace Tank {

void Game::getEvent(Utils &utils)
{
    while (utils.window.pollEvent(utils.event)) {
        // Exit
        utils.getExitEvent();
        if (utils.event.type == sf::Event::KeyPressed && utils.event.key.code == sf::Keyboard::Escape) {
            utils.window.close();
        }
    }
}

}
