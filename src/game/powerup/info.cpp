
#include "game/main.hpp"

using namespace utils;
namespace Tank {

sf::Sprite &Powerup::getSprite()
{
    return sprite;
}

int Powerup::getType()
{
    return type;
}

bool Powerup::isAnimationDone()
{
    return anim_done;
}

}
