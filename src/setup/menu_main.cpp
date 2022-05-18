
#include "tank.hpp"

void create_client(client_t &var, sf::RenderWindow &window, all_fonts_t &fonts, all_textures_t &textures)
{
    var.str = sf::IpAddress::getLocalAddress().toString();
    create_new_text(var.text, fonts.hud, var.str, 100, sf::Color::White, WINDOW_MIDDLE, 0.0f, SCALE_1);
    var.key = sf::Keyboard::Unknown;
}

void create_menu_main(menu_main_t &var, sf::RenderWindow &window, all_fonts_t &fonts, all_textures_t &textures)
{
    create_new_text(var.create, fonts.hud, "Create", 100, sf::Color::White, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 8 * 2), 0.0f, SCALE_1);
    create_new_text(var.join, fonts.hud, "Join", 100, sf::Color::White, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 8 * 3), 0.0f, SCALE_1);
    create_new_text(var.quit, fonts.hud, "Quit", 100, sf::Color::White, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 8 * 7), 0.0f, SCALE_1);
    var.part = MENU_MAIN_PART_DEFAULT;
    create_client(var.client, window, fonts, textures);
}
