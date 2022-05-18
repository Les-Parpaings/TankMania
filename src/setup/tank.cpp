
#include "tank.hpp"

//Load all data use in the game
void create_game(all_t &var)
{
    //window
    var.window.create(WINDOW_SIZE, std::string(WINDOW_NAME), sf::Style::Default);
    var.icon.loadFromFile(IMAGE_ICON);
    var.window.setIcon(var.icon.getSize().x, var.icon.getSize().y, var.icon.getPixelsPtr());
    var.window.setFramerateLimit(60);

    //utils
    var.part = PART_MENU_MAIN;
    var.exit = false;
    get_all_fonts(var.fonts);
    get_all_textures(var.textures);

    //parts
    create_lobby(var.lobby, var.window, var.fonts, var.textures);
    create_menu_main(var.menu_main, var.window, var.fonts, var.textures);
}
