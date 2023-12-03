
#include "game/main.hpp"

using namespace utils;
namespace Tank {

Player::Player()
{
    index = NONE;
    alive = false;
    kill = 0;
    victory = 0;
    speed = 0.0f;
    powerup = NO_POWERUP;
    can_shoot = true;
    blend = sf::BlendAlpha;
}

Player::Player(Utils &utils, PlayerSettings &settings)
{
    float diff = 180.0f / 7.0f;

    sf::Color colorPallet[6] = {
        sf::Color::Red,
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color(255, 128, 0)
    };

    index = settings.index;
    newSprite(sprite, I_PLAYER, R_PLAYER, sf::Vector2f(WALL_X + 50, WALL_Y + 50), S_PLAYER, colorPallet[index]);
    blend = sf::BlendAlpha;
    hud = HUD(utils, sf::Vector2f(1920.0f - (150.0f + diff), (diff + 75.0f) + (index * (diff + 150.0f))), sprite.getColor());
    alive = false; // false to increase remaining
    kill = 0;
    victory = 0;
    speed = 0.0f;
    powerup = NO_POWERUP;
    can_shoot = true;
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow &window)
{
    if (alive) {
        window.draw(sprite, blend);
    }
    hud.draw(window, powerup);
}

}
