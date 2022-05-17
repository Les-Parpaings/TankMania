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

typedef struct game {
    sf::RenderWindow window;
    sf::Event event;
    sf::Vector2i mouse_pos;
    int part;
    bool exit;
    all_fonts_t fonts;
    all_textures_t textures;
} game_t;

// *****************************************************************************
// SETUP
// *****************************************************************************

void create_game(game_t &var);

// *****************************************************************************
// EVENT
// *****************************************************************************

void get_event(game_t &var);

#endif /* !TANK_HPP_ */
