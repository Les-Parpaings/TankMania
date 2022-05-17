/*
** EPITECH PROJECT, 2022
** le_jeu_de_tank_trop_rigolo
** File description:
** lobby
*/

#pragma once

    #include "utils.hpp"
    #include "assets.hpp"

typedef struct lobby {
    //Client
    sf::IpAddress ip;
    sf::TcpSocket socket;

    //Server
    sf::TcpListener listener;

    std::string text;
    char buffer[2000];
    std::size_t received;
} lobby_t;
