
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

Player::Player()
{
}

Player::~Player()
{
}

void Player::create(Utils &utils)
{
    float x = 960.0f;
    float y = 540.0f;
    float width = 100.0f;
    float height = 100.0f;

    #if COLLISION_TEST == 0
    newSprite(sprite, TEXTURE_NONE, sf::IntRect(0, 0, 30, 60), sf::Vector2f(WALL_X + 50, WALL_Y + 50), VECTOR_1, sf::Color::Red);
    #else
    newSprite(sprite, TEXTURE_NONE, sf::IntRect(0, 0, 40, 40), sf::Vector2f(x - width, y - height), VECTOR_1, sf::Color::Red);

    test = sf::VertexArray(sf::Quads, 4);
    test[0].position = sf::Vector2f(x        , y);
    test[1].position = sf::Vector2f(x + width, y);
    test[2].position = sf::Vector2f(x + width, y + height);
    test[3].position = sf::Vector2f(x        , y + height);
    #endif

    newSprite(line, TEXTURE_NONE, sf::IntRect(0, 0, 4, 60), sprite.getPosition(), VECTOR_1, sf::Color::Blue);
    line.setOrigin(sf::Vector2f(line.getGlobalBounds().width / 2, line.getGlobalBounds().height));
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(line);
    window.draw(sprite);
    #if COLLISION_TEST == 1
    window.draw(&test[0], test.getVertexCount(), sf::Quads);
    #endif
}

}
