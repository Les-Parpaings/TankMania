
#include "game/main.hpp"
#include <cmath>

using namespace utils;
namespace Tank {

void movePlayer(sf::Sprite &sprite, directions index, bool reverse, float velocity)
{
    float x = calculMove(sprite.getRotation(), 5.0f * velocity);
    float y = calculMove(sprite.getRotation() + 270.0f, 5.0f * velocity);

    if (reverse) {
        x = -x;
        y = -y;
    }
    if (index == DOWN) {
        x = -x;
        y = -y;
    }

    sprite.move(x, y);
}

void Player::checkOneMovement(Walls &walls, directions index)
{
    if (speed < 1.0f)
        speed += 0.1f;
    movePlayer(sprite, index, false, speed);
    for (auto &wall : walls) {
        if (isColliding(sprite, wall)) {
            movePlayer(sprite, index, true, speed);
            speed = 0.0f;
            return;
        }
    }
}

void Player::checkOneRotation(Walls &walls, float angle)
{
    sprite.rotate(angle);
    for (auto &wall : walls) {
        if (isColliding(sprite, wall)) {
            sprite.rotate(-angle);
            return;
        }
    }
}

void Player::doMovement(Walls &walls)
{
    if (moveForward(index)) {
        checkOneMovement(walls, UP);
    } else if (moveBackward(index)) {
        checkOneMovement(walls, DOWN);
    } else {
        speed = 0.0f;
    }

    if (rotateForward(index)) {
        checkOneRotation(walls, 5.0f);
    }
    if (rotateBackward(index)) {
        checkOneRotation(walls, -5.0f);
    }
}


}
