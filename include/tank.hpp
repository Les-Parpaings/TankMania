/*
** EPITECH PROJECT, 2022
** le_jeu_de_tank_trop_rigolo
** File description:
** tank
*/

#ifndef TANK_HPP_
    #define TANK_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Network.hpp>

    #include <iostream>

    #include "utils.hpp"
    #include "assets.hpp"
    #include "game.hpp"
    #include "lobby.hpp"

enum part {
    PART_MENU_MAIN,
    PART_LOBBY,
    PART_GAME
};

typedef struct all {
    sf::RenderWindow window;
    sf::Event event;
    sf::Vector2i mouse_pos;
    int part;
    bool exit;
    all_fonts_t fonts;
    all_textures_t textures;
} all_t;

// *****************************************************************************
// SETUP
// *****************************************************************************

void create_game(all_t &var);

// *****************************************************************************
// EVENT
// *****************************************************************************

void get_event(all_t &var);

// *****************************************************************************
// LOBBY
// *****************************************************************************

void do_lobby(all_t &var);
void get_event_lobby(all_t &var);

#endif /* !TANK_HPP_ */
