
#include "tank.hpp"

void display_menu_main(menu_main_t &var, sf::RenderWindow &window, int part)
{
    window.draw(var.create);
    window.draw(var.join);
    window.draw(var.quit);

    switch (part) {
        case MENU_MAIN_PART_CLIENT:
            display_client(var.client, window);
            break;
    }
}

void do_menu_main(all_t &var)
{
    display_menu_main(var.menu_main, var.window, MENU_MAIN_PART_DEFAULT);
}
