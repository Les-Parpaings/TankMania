
#include "tank.hpp"

//Get all event in the game
void get_event(all_t &var)
{
    while (var.window.pollEvent(var.event)) {
        if (var.event.type == sf::Event::Closed) {
            var.exit = true;
            return;
        }

        var.mouse_pos = sf::Mouse::getPosition(var.window);
        switch (var.part) {
            case PART_MENU_MAIN:
                get_event_menu_main(var);
                break;
            case PART_CREATE:
                get_event_lobby(var);
                break;
        }
    }
}
