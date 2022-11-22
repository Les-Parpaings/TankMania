
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

void Player::getEvent(Utils &utils)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        std::cout << "Z" << std::endl;
    }
}

}
