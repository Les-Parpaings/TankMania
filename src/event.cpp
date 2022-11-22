
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

void get_event_all(TankMania &var, Utils &utils)
{
    while (utils.window.pollEvent(utils.event)) {
        utils.getExitEvent();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            utils.transition.setAnimValue(FADE_IN);

        switch (var.part) {
            case PART_MENU:
                break;
            case PART_GAME:
                get_event_game(var.game, utils);
                break;
        }
    }
}

}
