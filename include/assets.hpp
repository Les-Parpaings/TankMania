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
    #define IMAGE_BACKGROUND     "assets/image/background.png"

    #define FONT_TITLE           "assets/font/titan_one.ttf"

typedef struct all_fonts {
    sf::Font title;
} all_fonts_t;

typedef struct all_textures {
    sf::Texture background;
} all_textures_t;

void get_all_fonts(all_fonts_t &fonts);
void get_all_textures(all_textures_t &textures);
