
#include "game/main.hpp"
#include <cmath>

using namespace utils;
namespace Tank {

void Player::restart(int x, int y)
{
    // Static increase: nbr of player alive
    if (!alive)
        remaning++;

    sprite.setPosition(WALL_X + 50 + 100 * x, WALL_Y + 50 + 100 * y);
    sprite.setRotation(Random::getRandom(4) * 90);
    alive = true;
    hud.setAlive();

    if (powerup == PowerupsList::CAMO) {
        auto color = this->sprite.getColor();
        color.a = 255;
        this->sprite.setColor(color);
    }
    powerup = NO_POWERUP;
}

bool Player::isAlive()
{
    return alive;
}

}
