
#include "game/main.hpp"

using namespace utils;
namespace Tank {

sf::CircleShape &Projectile::getCircle()
{
    return circle;
}

float Projectile::getTime()
{
    return clock.getElapsedTime().asSeconds();
}

bool Projectile::isOwner(Player *player)
{
    if (player == owner) {
        return true;
    } else {
        return false;
    }
}

Player *Projectile::getOwner()
{
    return owner;
}

int Projectile::getPowerupType()
{
    return powerup;
}

}
