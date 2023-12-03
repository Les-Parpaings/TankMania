
#include "game/main.hpp"

using namespace utils;
namespace Tank {

Powerup::Powerup(Utils &utils, sf::Vector2f pos)
{
    int limit = PowerupsList::POWERUP_SIZE - 1;
    type = Random::getRandom(limit);

    std::string powerupPallet[limit] = {
        "powerups/big",
        "powerups/shotgun",
        "powerups/minigun",
        "powerups/bomb",
        "powerups/camo"
    };
    newSprite(sprite, IMAGE(powerupPallet[type]), R_POWERUPS, pos, VECTOR_0);

    anim_done = false;
    rot_nbr = Random::getRandomInRange(48, 56);
    rot_index = 0;
}

Powerup::~Powerup()
{
}

void Powerup::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

}
