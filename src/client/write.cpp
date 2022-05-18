
#include "tank.hpp"

void write_letter(client_t &var)
{
    char new_letter;

    if (var.key == sf::Keyboard::SemiColon) {
        new_letter = '.';
    } else if (var.key == sf::Keyboard::Quote) {
        new_letter = '4';
    } else if (var.key == sf::Keyboard::Hyphen) {
        new_letter = '6';
    } else {
        new_letter = var.key + 22;
    }
    var.str.push_back(new_letter);
    set_text_string(var.text, var.str, SET_TEXT_MID);
}

void enter_address(all_t &var)
{
    var.part = PART_MENU_MAIN;
}

void delete_letter(client_t &var)
{
    if (var.str.length() > 0) {
        var.str.pop_back();
        set_text_string(var.text, var.str, SET_TEXT_MID);
    }
}

void set_new_letter(all_t &var)
{
    if (var.menu_main.client.key != sf::Keyboard::Unknown) {
        if (var.menu_main.client.key == sf::Keyboard::Enter) {
            enter_address(var);
        } else if (var.menu_main.client.key == sf::Keyboard::BackSpace) {
            delete_letter(var.menu_main.client);
        } else {
            write_letter(var.menu_main.client);
        }
        var.menu_main.client.key = sf::Keyboard::Unknown;
    }
}
