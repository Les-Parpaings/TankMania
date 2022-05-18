/*
** EPITECH PROJECT, 2022
** assets.hpp
** File description:
** assets
*/

#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Network.hpp>

    #include <iostream>

    #define IMAGE_ICON           "assets/image/icon.png"

    #define FONT_HUD             "assets/font/titan_one.ttf"

//Font use in the gamee
typedef struct all_fonts {
    sf::Font hud;
} all_fonts_t;

//Texture use in the game
typedef struct all_textures {
    // sf::Texture background;
} all_textures_t;

void get_all_fonts(all_fonts_t &fonts);
void get_all_textures(all_textures_t &textures);
