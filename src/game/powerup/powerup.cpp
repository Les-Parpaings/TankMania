
#include "game/main.hpp"

using namespace utils;
namespace Tank {

Powerup::Powerup(Utils &utils, sf::Vector2f pos)
{
    newSprite(sprite, TEXTURE_NONE, sf::IntRect(0, 0, 50, 50), pos, VECTOR_0, sf::Color::Blue);
    // type = Random::getRandomInRange(1, 6);
    type = PowerupsList::CAMO;

    anim_done = false;
    rot_nbr = Random::getRandomInRange(48, 56);
    rot_index = 0;
}

Powerup::~Powerup()
{
}

void Powerup::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

}
