
#include "tank.hpp"

int main(int ac, char **av)
{
    game_t var;
    create_game(var);

    while (var.window.isOpen()) {
        var.window.clear(sf::Color::Black);

        get_event(var);
        if (var.exit == true)
            var.window.close();

        switch (var.part) {
            /* case PART_MENU_MAIN:
                do_main_menu(var);
                break;
            case PART_CHOICE_WORD:
                do_choice_word(var);
                break;
            case PART_GAME:
                do_game(var);
                break;
            case PART_ENDGAME:
                // end_game
                break; */
        }
        var.window.display();
    }

    return EXIT_SUCCESS;
}
