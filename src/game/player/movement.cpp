
#include "tankmania.hpp"
#include <cmath>

using namespace utils;
namespace Tank {

float calculMove(float angle)
{
    float value = angle;
    bool reverse = false;

    // Y case, if it exceed 360°
    if (value >= 360.0f)
        value -= 360.0f;

    // If angle is in the negative part
    if (value > 180.0f) {
        value -= 180.0f;
        reverse = true;
    }

    if (value > 90.0f)
        value = 180.0f - value;
    value /= 18;

    if (reverse)
        value = -value;

    return value;
}

void movePlayer(sf::Sprite &sprite, directions index, bool reverse)
{
    float x = calculMove(sprite.getRotation());
    float y = calculMove(sprite.getRotation() + 270.0f);

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
    movePlayer(sprite, index, false);
    #if COLLISION_TEST == 0
    for (auto &wall : walls) {
        if (isColliding(wall)) {
            movePlayer(sprite, index, true);
            return;
        }
    }
    #else
    if (isColliding(test)) {
        movePlayer(sprite, index, true);
    }
    #endif
}

void Player::checkOneRotation(Walls &walls, float angle)
{
    sprite.rotate(angle);
    for (auto &wall : walls) {
        if (isColliding(wall)) {
            sprite.rotate(-angle);
            return;
        }
    }
}

void Player::doMovement(Walls &walls)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        checkOneMovement(walls, UP);
        line.setPosition(sprite.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        checkOneMovement(walls, DOWN);
        line.setPosition(sprite.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        checkOneRotation(walls, -5.0f);
        line.setRotation(sprite.getRotation());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        checkOneRotation(walls, 5.0f);
        line.setRotation(sprite.getRotation());
    }
}


}
