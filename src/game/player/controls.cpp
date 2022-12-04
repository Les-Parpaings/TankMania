
#include "game/main.hpp"
#include <cmath>

using namespace utils;
namespace Tank {

bool moveForward(int index)
{
    bool ret = false;

    if (index == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            ret = true;
        }
    } else if (index == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            ret = true;
        }
    } else {
        int joystickIndex = index - 2;

        if (sf::Joystick::isConnected(joystickIndex)) {
            float axis = sf::Joystick::getAxisPosition(joystickIndex, sf::Joystick::Axis::Y);
            if (axis <= -50.0f) {
                ret = true;
            }
        }
    }

    return ret;
}

bool moveBackward(int index)
{
    bool ret = false;

    if (index == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            ret = true;
        }
    } else if (index == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            ret = true;
        }
    } else {
        int joystickIndex = index - 2;

        if (sf::Joystick::isConnected(joystickIndex)) {
            float axis = sf::Joystick::getAxisPosition(joystickIndex, sf::Joystick::Axis::Y);
            if (axis >= 50.0f) {
                ret = true;
            }
        }
    }

    return ret;
}

bool rotateForward(int index)
{
    bool ret = false;

    if (index == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ret = true;
        }
    } else if (index == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ret = true;
        }
    } else {
        int joystickIndex = index - 2;

        if (sf::Joystick::isConnected(joystickIndex)) {
            float axis = sf::Joystick::getAxisPosition(joystickIndex, sf::Joystick::Axis::U);
            if (axis >= 50.0f) {
                ret = true;
            }
        }
    }

    return ret;
}

bool rotateBackward(int index)
{
    bool ret = false;

    if (index == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            ret = true;
        }
    } else if (index == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ret = true;
        }
    } else {
        int joystickIndex = index - 2;

        if (sf::Joystick::isConnected(joystickIndex)) {
            float axis = sf::Joystick::getAxisPosition(joystickIndex, sf::Joystick::Axis::U);
            if (axis <= -50.0f) {
                ret = true;
            }
        }
    }

    return ret;
}

bool shoot(int index, bool &can_shoot, int powerup, sf::Clock &minigun_clock)
{
    bool ret = false;

    if (index == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            if (can_shoot) {
                ret = true;
                can_shoot = false;
            }
        } else {
            can_shoot = true;
        }
    } else if (index == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (can_shoot) {
                ret = true;
                can_shoot = false;
            }
        } else {
            can_shoot = true;
        }
    } else {
        int joystickIndex = index - 2;

        if (sf::Joystick::isConnected(joystickIndex)) {
            float axis = sf::Joystick::getAxisPosition(joystickIndex, sf::Joystick::Axis::R);
            if (axis >= 0.0f) {
                if (can_shoot) {
                    ret = true;
                    can_shoot = false;
                }
            } else {
                can_shoot = true;
            }
        }
    }

    if (powerup == PowerupsList::MINIGUN) {
        can_shoot = true;
        if (minigun_clock.getElapsedTime().asSeconds() >= 5.0f) {
            powerup = NO_POWERUP;
        }
    }

    return ret;
}

}
