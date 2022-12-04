
#include "game/main.hpp"

using namespace utils;
namespace Tank {

Projectile::Projectile()
{
    owner = nullptr;
}

Projectile::Projectile(Player *player, int powerup_type, sf::Vector2f pos, float angle)
{
    float radius = 4.0f;
    if (powerup_type == PowerupsList::BIG)
        radius = 12.0f;
    if (powerup_type == PowerupsList::BOMBE)
        radius = 8.0f;
    if (powerup_type == PowerupsList::MINIGUN)
        radius = 2.0f;

    circle.setRadius(radius);
    circle.setPointCount(radius * 2);
    circle.setPosition(pos);
    circle.setRotation(angle);
    circle.setOrigin(circle.getGlobalBounds().width / 2.0f, circle.getGlobalBounds().height / 2.0f);
    circle.setFillColor(sf::Color::Black);

    owner = player;
    powerup = powerup_type;
}

Projectile::~Projectile()
{
}

void Projectile::draw(sf::RenderWindow &window)
{
    window.draw(circle);
}

}
