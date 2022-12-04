
#include "game/main.hpp"

using namespace utils;
namespace Tank
{

int Player::remaning = 0;

int main_game(Utils &utils, Settings &settings)
{
    Game var(utils, settings);

    while (utils.window.isOpen()) {
        var.getEvent(utils);
        var.doLogic(utils);
        var.draw(utils);
    }

    return EXIT_SUCCESS;
}

} // namespace Tank
