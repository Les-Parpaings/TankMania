
#include "tank.hpp"

void get_event(game_t &var)
{
    while (var.window.pollEvent(var.event)) {
        if (var.event.type == sf::Event::Closed) {
            var.exit = true;
            return;
        }

        var.mouse_pos = sf::Mouse::getPosition(var.window);
        switch (var.part) {
            /* case PART_MENU_MAIN:
                get_event_main_menu(var);
                break;
            case PART_CHOICE_WORD:
                get_event_choice_word(var);
                break;
            case PART_GAME:
                get_event_game(var);
                break;
            case PART_ENDGAME:
                // end_game
                break; */
        }
    }
}
