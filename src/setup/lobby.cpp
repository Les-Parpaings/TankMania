
#include "tank.hpp"

void create_lobby(lobby_t &var, sf::RenderWindow &window, all_fonts_t &fonts, all_textures_t &textures)
{
    var.ip = sf::IpAddress::getLocalAddress();
    var.text = "Connected to ";

    std::cout << "IP: " << var.ip.toString() << std::endl;
}
