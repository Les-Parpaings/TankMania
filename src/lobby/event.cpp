
#include "tank.hpp"

void get_event_lobby(all_t &var)
{
    //Server
    if (var.event.type == sf::Event::KeyPressed && var.event.key.code == sf::Keyboard::S) {
        var.lobby.listener.listen(2000);
        var.lobby.listener.accept(var.lobby.socket);
        var.lobby.text += "Server";
    }

    //Client
    if (var.event.type == sf::Event::KeyPressed && var.event.key.code == sf::Keyboard::C) {
        var.lobby.socket.connect(var.lobby.ip, 2000);
        var.lobby.text += "Client";
    }

    var.lobby.socket.send(var.lobby.text.c_str(), var.lobby.text.length() + 1);
    var.lobby.socket.receive(var.lobby.buffer, sizeof(var.lobby.buffer), var.lobby.received);
}
