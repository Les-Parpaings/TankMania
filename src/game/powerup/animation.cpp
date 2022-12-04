
#include "game/main.hpp"

using namespace utils;
namespace Tank {

void Powerup::doAnimation()
{
    sprite.rotate(30.0f);

    auto scale = sprite.getScale();
    sprite.setScale(scale + sf::Vector2f(0.015f, 0.015f));

    rot_index++;
    if (rot_index >= rot_nbr) {
        anim_done = true;
    }
}

}
