
#include "tank.hpp"

void display_client(client_t &var, sf::RenderWindow &window)
{
    window.draw(var.text);
}

void do_client(all_t &var)
{
    set_new_letter(var);
    display_menu_main(var.menu_main, var.window, MENU_MAIN_PART_CLIENT);
}
