/*
** EPITECH PROJECT, 2022
** le_jeu_de_tank_trop_rigolo
** File description:
** lobby
*/

#pragma once

    #include "utils.hpp"
    #include "assets.hpp"

//Data use in network system
typedef struct network {
    int user_id;
    bool is_host;

    //Client
    sf::IpAddress ip;
    sf::TcpSocket socket;
    char buffer[2000];

    //Server
    sf::TcpListener listener;

} network_t;

//Data use in lobby when you click on Create button on main menu
typedef struct lobby {

} lobby_t;
