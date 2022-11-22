
#include "utils/utils.hpp"

namespace utils {

bool isInView(sf::Text &text, sf::View &view)
{
    sf::Vector2f pos(text.getPosition().x, text.getPosition().y);
    sf::Vector2f size(view.getSize().x / 2.0f, view.getSize().y / 2.0f);
    sf::Vector2f center(view.getCenter().x, view.getCenter().y);

    if (pos.x >= center.x - size.x && pos.x <= center.x + size.x
    && pos.y >= center.y - size.y && pos.y <= center.y + size.y) {
        return true;
    } else {
        return false;
    }
}

bool isInView(sf::Sprite &sprite, sf::View &view)
{
    float y = sprite.getPosition().y;
    float size = view.getSize().y / 2.0f;
    float center = view.getCenter().y;

    if (y >= center - size && y <= center + size) {
        return true;
    } else {
        return false;
    }
}

bool isInView(sf::Vector2i pos, sf::View &view)
{
    sf::Vector2f size(view.getSize().x / 2.0f, view.getSize().y / 2.0f);
    sf::Vector2f center(view.getCenter().x, view.getCenter().y);

    if (pos.x >= center.x - size.x && pos.x <= center.x + size.x
    && pos.y >= center.y - size.y && pos.y <= center.y + size.y) {
        return true;
    } else {
        return false;
    }
}

bool isInView(sf::Vector2f pos, sf::View &view)
{
    sf::Vector2f size(view.getSize().x / 2.0f, view.getSize().y / 2.0f);
    sf::Vector2f center(view.getCenter().x, view.getCenter().y);

    if (pos.x >= center.x - size.x && pos.x <= center.x + size.x
    && pos.y >= center.y - size.y && pos.y <= center.y + size.y) {
        return true;
    } else {
        return false;
    }
}

bool isMouseInView(sf::RenderWindow &window, sf::View &view)
{
    if (isInView(window.mapPixelToCoords(sf::Mouse::getPosition(window), view), view)) {
        return true;
    } else {
        return false;
    }
}

}
