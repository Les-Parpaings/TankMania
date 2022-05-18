
#include "tank.hpp"

//Check mouse position and if it is over a text
void get_menu_main_selected(all_t &var)
{
    var.menu_main.create.setFillColor(sf::Color::White);
    var.menu_main.join.setFillColor(sf::Color::White);
    var.menu_main.quit.setFillColor(sf::Color::White);
    if (check_pos_mouse(var.mouse_pos, var.menu_main.create.getGlobalBounds(), var.window)) {
        var.menu_main.create.setFillColor(TEXT_SELECTED_COLOR);
    }
    if (check_pos_mouse(var.mouse_pos, var.menu_main.join.getGlobalBounds(), var.window)) {
        var.menu_main.join.setFillColor(TEXT_SELECTED_COLOR);
    }
    if (check_pos_mouse(var.mouse_pos, var.menu_main.quit.getGlobalBounds(), var.window)) {
        var.menu_main.quit.setFillColor(TEXT_SELECTED_COLOR);
    }
}

void get_menu_main_pressed(all_t &var)
{
    if (check_pos_mouse(var.mouse_pos, var.menu_main.create.getGlobalBounds(), var.window)) {
        var.menu_main.create.setFillColor(sf::Color::Yellow);
    }
    if (check_pos_mouse(var.mouse_pos, var.menu_main.join.getGlobalBounds(), var.window)) {
        var.menu_main.join.setFillColor(sf::Color::Yellow);
    }
    if (check_pos_mouse(var.mouse_pos, var.menu_main.quit.getGlobalBounds(), var.window)) {
        var.exit = true;
        var.menu_main.quit.setFillColor(sf::Color::Yellow);
    }
}

void get_event_menu_main(all_t &var)
{
    get_menu_main_selected(var);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        get_menu_main_pressed(var);
    }
}
