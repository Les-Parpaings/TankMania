
#include "utils.hpp"

using namespace sf;

//Use to create a sfml text
void create_new_text(sf::Text &text, sf::Font &font, std::string str, int size, sf::Color color, sf::Vector2f pos, float angle, sf::Vector2f scale)
{
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(pos);
    text.setRotation(angle);
    text.setScale(scale);
    text.setOrigin(Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2));
    text.setOutlineThickness(3.0f);
}

//Use to create sfml sprite
void create_new_sprite(sf::Sprite &sprite, sf::Texture &texture, sf::IntRect rect, sf::Vector2f pos, float angle, sf::Vector2f scale)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setPosition(pos);
    sprite.setRotation(angle);
    sprite.setScale(scale);
    sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
}
