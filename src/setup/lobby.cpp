
#include "tank.hpp"

void create_lobby(lobby_t &var)
{
    var.ip = sf::IpAddress::getLocalAddress();
    var.text = "Connected to ";

    std::cout << "IP: " << var.ip.toString() << std::endl;
}
