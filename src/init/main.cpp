
#include "tank.hpp"

int main(int ac, char **av)
{
    all_t var;
    create_game(var);

    while (var.window.isOpen()) {
        var.window.clear(sf::Color::Black);

        get_event(var);
        if (var.exit == true)
            var.window.close();

        switch (var.part) {
            case PART_LOBBY:
                do_lobby(var);
                break;
        }
        var.window.display();
    }

    return EXIT_SUCCESS;
}