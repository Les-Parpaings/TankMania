
#include "tank.hpp"

//Get event in the lobby scene
void get_event_lobby(all_t &var)
{
    //Client
    if (var.event.type == sf::Event::KeyPressed && var.event.key.code == sf::Keyboard::C) {
        var.network.socket.connect(var.network.ip, 2000);
    }
}
