
#include "tank.hpp"

void create_game(game_t &var)
{
    var.window.create(WINDOW_SIZE, std::string(WINDOW_NAME), sf::Style::Default);
    var.part = 0;
    var.exit = false;
    get_all_fonts(var.fonts);
    get_all_textures(var.textures);
}
