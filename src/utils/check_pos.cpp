
#include "utils.hpp"

using namespace sf;

//Return true if mouse pos is in the FloatRect size
bool check_pos_mouse(sf::Vector2i &mouse, const sf::FloatRect &size, sf::RenderWindow &window)
{
    Vector2f pos_mouse = window.mapPixelToCoords(mouse);

    if (pos_mouse.x >= size.left && pos_mouse.x <= size.left + size.width
    && pos_mouse.y >= size.top && pos_mouse.y <= size.top + size.height) {
        return true;
    } else {
        return false;
    }
}
