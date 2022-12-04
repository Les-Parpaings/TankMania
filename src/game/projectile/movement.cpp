
#include "game/main.hpp"
#include <cmath>
#include <unistd.h>

using namespace utils;
namespace Tank {

Walls::iterator projectileHasCollision(sf::CircleShape &circle, Walls &walls)
{
    for (auto it = walls.begin(); it != walls.end(); it++) {
        if (isCircleColliding(circle, it->getBounds())) {
            return it;
        }
    }
    return walls.end();
}

sf::Vector2f moveProjectile(sf::CircleShape &circle, bool reverse, float velocity)
{
    float x = calculMove(circle.getRotation(), velocity);
    float y = calculMove(circle.getRotation() + 270.0f, velocity);

    sf::Vector2f move(x, y);
    if (reverse) {
        move = -move;
    }

    return move;
}

float getAngleTopBottom(float angle)
{
    if (angle >= 90.0f)
        angle -= 360.0f;

    angle = 180 - angle;

    return angle;
}

float getAngleLeftRight(float angle)
{
    angle = -angle;
    return angle;
}

void Projectile::getNewRotation(sf::VertexArray &wall)
{
    float angle = circle.getRotation();

    sf::Vector2f pos = circle.getPosition();
    float left   = wall[0].position.x;
    float top    = wall[0].position.y;
    float right  = wall[2].position.x;
    float bottom = wall[2].position.y;

    if (pos.x >= left && pos.x <= right) { // Vertical
        if (pos.y < top) {
            angle = getAngleTopBottom(angle);
        } else {
            angle = getAngleTopBottom(angle);
        }
    } else { // Horizontal
        if (pos.x < left) {
            angle = getAngleLeftRight(angle);
        } else {
            angle = getAngleLeftRight(angle);
        }
    }

    circle.setRotation(angle);
}

bool Projectile::doMovement(Walls &walls)
{
    auto move = moveProjectile(circle, false, 10.0f);
    circle.move(move);

    if (powerup != PowerupsList::BIG && powerup != PowerupsList::BOMBE_EXPLOSION) {
        auto wall = projectileHasCollision(circle, walls);
        if (wall != walls.end()) {

            if (powerup == PowerupsList::BOMBE)
                return true;

            circle.move(-move);
            getNewRotation(*wall);
            return false;
        }
    }
    return false;
}

}
