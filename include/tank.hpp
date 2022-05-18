/*
** EPITECH PROJECT, 2022
** le_jeu_de_tank_trop_rigolo
** File description:
** tank
*/

#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Network.hpp>

    #include <iostream>

    #include "utils.hpp"
    #include "assets.hpp"
    #include "game.hpp"
    #include "menu_main.hpp"
    #include "lobby.hpp"

//Different scene of the game
enum part {
    PART_MENU_MAIN,
    PART_JOIN,
    PART_CREATE,
    PART_GAME
};

//Data for all the game
typedef struct all {
    //windows
    sf::RenderWindow window;
    sf::Image icon;
    sf::Event event;
    sf::Vector2i mouse_pos;

    //utils
    int part;
    bool exit;
    all_fonts_t fonts;
    all_textures_t textures;

    //parts
    menu_main_t menu_main;
    lobby_t lobby;

    //network
    network_t network;
} all_t;

// *****************************************************************************
// INIT
// *****************************************************************************

void create_game(all_t &var);
void get_event(all_t &var);

// *****************************************************************************
// MENU_MAIN
// *****************************************************************************

void do_menu_main(all_t &var);
void create_menu_main(menu_main_t &var, sf::RenderWindow &window, all_fonts_t &fonts, all_textures_t &textures);
void get_event_menu_main(all_t &var);

// *****************************************************************************
// LOBBY
// *****************************************************************************

void do_lobby(all_t &var);
void create_lobby(lobby_t &var, sf::RenderWindow &window, all_fonts_t &fonts, all_textures_t &textures);
void get_event_lobby(all_t &var);
void server(all_t &var);
