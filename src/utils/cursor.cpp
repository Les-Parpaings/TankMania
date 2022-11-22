
#include "utils/utils.hpp"
#include <functional>

namespace utils {

// ****************************************************************************
// CURSOR
// ****************************************************************************

Cursor::Cursor()
{
    this->texture.loadFromFile(PATH_CURSOR);
    this->sprite.setTexture(texture);

    sf::IntRect rect = this->sprite.getTextureRect();
    sf::Vector2f scale(1.0f / (rect.width / 50.0f), 1.0f / (rect.height / 50.0f));
    this->sprite.setScale(scale);
}

Cursor::~Cursor()
{
}

void Cursor::draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void Cursor::setCursorPosition(sf::RenderWindow &window)
{
    if (!window.hasFocus()) {
        window.setMouseCursorVisible(true);
        return;
    } else {
        window.setMouseCursorVisible(false);
    }

    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(1)) {
        sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sprite.setPosition(pos);
        clock.restart();
    }
}

void Cursor::hideCursor()
{
    sf::Color color = sprite.getColor();

    if (color != sf::Color::Transparent) {
        sprite.setColor(sf::Color::Transparent);
    }
}

void Cursor::showCursor()
{
    sf::Color color = sprite.getColor();

    if (color != sf::Color::White) {
        sprite.setColor(sf::Color::White);
    }
}

}
