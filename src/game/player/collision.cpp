
#include "game/main.hpp"

using namespace utils;
namespace Tank {

bool Player::touchedProjectile(Projectile &projectile)
{
    if (projectile.getTime() < 0.1f && projectile.isOwner(this))
        return false;
    if (powerup == PowerupsList::CAMO)
        return false;

    if (isColliding(projectile.getCircle(), sprite)) {
        remaning--;
        alive = false;
        hud.setDead();
        if (!projectile.isOwner(this)) {
            projectile.getOwner()->addKill();
        }
        return true;
    } else {
        return false;
    }
}

bool Player::touchedPowerup(Powerup &powerup)
{
    if (isColliding(powerup.getSprite(), sprite)) {
        this->powerup = powerup.getType();
        if (this->powerup == PowerupsList::MINIGUN)
            this->minigun_clock.restart();
        if (this->powerup == PowerupsList::CAMO) {
            this->camo_clock.restart();
            this->sprite.setColor(sf::Color(255, 0, 0, 64));
        }
        return true;
    } else {
        return false;
    }
}

}
