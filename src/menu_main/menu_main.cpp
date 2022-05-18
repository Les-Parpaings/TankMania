
#include "tank.hpp"

void display_menu_main(menu_main_t &var, sf::RenderWindow &window)
{
    window.draw(var.create);
    window.draw(var.join);
    window.draw(var.quit);
}

void do_menu_main(all_t &var)
{
    display_menu_main(var.menu_main, var.window);
}
