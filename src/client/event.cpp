
#include "tank.hpp"

void get_event_client(all_t &var)
{
    if (var.event.type == sf::Event::KeyPressed) {
        if (var.event.key.code >= sf::Keyboard::Num0 && var.event.key.code <= sf::Keyboard::Num9) { // Digits
            var.menu_main.client.key = var.event.key.code;
        } else if (var.event.key.code == sf::Keyboard::Enter) { // Enter
            var.menu_main.client.key = var.event.key.code;
        } else if (var.event.key.code == sf::Keyboard::BackSpace) { // Backspace
            var.menu_main.client.key = var.event.key.code;
        } else if (var.event.key.code == sf::Keyboard::SemiColon) { // Point
            var.menu_main.client.key = var.event.key.code;
        } else if (var.event.key.code == sf::Keyboard::Hyphen || var.event.key.code == sf::Keyboard::Quote) { // Point
            var.menu_main.client.key = var.event.key.code;
        }
    }
}
