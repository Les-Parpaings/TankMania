
#include "game/main.hpp"
#include <cmath>

using namespace utils;
namespace Tank {

void Player::launchProjectile(Projectiles &list)
{
    auto OBB = OrientedBoundingBox(sprite);

    sf::Vector2f pos{
        OBB.points[0].x + (OBB.points[1].x - OBB.points[0].x) / 2,
        OBB.points[0].y + (OBB.points[1].y - OBB.points[0].y) / 2
    };

    if (powerup == PowerupsList::SHOTGUN) {
        for (int i = -30; i < 30; i += 5) {
            list.push_back(Projectile(this, powerup, pos, sprite.getRotation() + i));
        }
    } else {
        list.push_back(Projectile(this, powerup, pos, sprite.getRotation()));
    }

    if (powerup != NO_POWERUP && powerup != MINIGUN && powerup != CAMO)
        powerup = NO_POWERUP;
}

void Player::doShooting(Utils &utils, Projectiles &list)
{
    if (shoot(index, can_shoot, powerup, minigun_clock)) {
        launchProjectile(list);
    }
    if (powerup == PowerupsList::CAMO) {
        if (camo_clock.getElapsedTime().asSeconds() >= 5.0f) {
            powerup = NO_POWERUP;
            sprite.setColor(sf::Color::Red);
        }
    }
}

}
