
#include "tank.hpp"

void create_game(all_t &var)
{
    var.window.create(WINDOW_SIZE, std::string(WINDOW_NAME), sf::Style::Default);
    var.part = PART_LOBBY;
    var.exit = false;
    get_all_fonts(var.fonts);
    get_all_textures(var.textures);
}
