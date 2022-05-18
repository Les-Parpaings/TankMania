/*
** EPITECH PROJECT, 2022
** le_jeu_de_tank_trop_rigolo
** File description:
** menu_main
*/

#pragma once

    #include "utils.hpp"
    #include "assets.hpp"

//different part of the menu main
enum menu_main_part {
    MENU_MAIN_PART_DEFAULT,
    MENU_MAIN_PART_CLIENT
};

typedef struct client {
    sf::Text text;
    std::string str;
    sf::Keyboard::Key key;
} client_t;

typedef struct menu_main {
    sf::Text create;
    sf::Text join;
    sf::Text quit;
    int part;

    client_t client;
} menu_main_t;
