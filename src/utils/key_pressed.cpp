
#include "utils.hpp"

using namespace sf;

bool is_key_pressed(int key, sf::Event &event)
{
    if (event.key.code == key && event.type ==  Event::EventType::KeyPressed) {
        return true;
    } else {
        return false;
    }
}
