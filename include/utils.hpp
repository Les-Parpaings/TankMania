/*
** EPITECH PROJECT, 2021
** util.h
** File description:
** util
*/

#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Network.hpp>

    #include <iostream>

    #define WINDOW_MIN_WIDTH        800
    #define WINDOW_MIN_HEIGHT       600
    #define WINDOW_MAX_WIDTH        1920
    #define WINDOW_MAX_HEIGHT       1080
    #define WINDOW_SIZE             sf::VideoMode(1920, 1080)
    #define WINDOW_NAME             "TankMania"

    #define POS_0               0.0f, 0.0f
    #define POS_MID             window.getSize().x / 2, window.getSize().y / 2

    #define POS_X_TIER_1        window.getSize().x / 3,     window.getSize().y / 2
    #define POS_X_TIER_2        window.getSize().x / 3 * 3, window.getSize().y / 2
    #define POS_X_QUART_1       window.getSize().x / 4,     window.getSize().y / 2
    #define POS_X_QUART_3       window.getSize().x / 4 * 3, window.getSize().y / 2
    #define POS_X_FIVE_1        window.getSize().x / 5,    window.getSize().y / 2
    #define POS_X_FIVE_2        window.getSize().x / 5 * 2, window.getSize().y / 2
    #define POS_X_FIVE_3        window.getSize().x / 5 * 3, window.getSize().y / 2
    #define POS_X_FIVE_4        window.getSize().x / 5 * 4, window.getSize().y / 2

    #define POS_Y_TIER_1        window.getSize().x / 2, window.getSize().y / 3
    #define POS_Y_TIER_2        window.getSize().x / 2, window.getSize().y / 3 * 3
    #define POS_Y_QUART_1       window.getSize().x / 2, window.getSize().y / 4
    #define POS_Y_QUART_3       window.getSize().x / 2, window.getSize().y / 4 * 3
    #define POS_Y_FIVE_1        window.getSize().x / 2, window.getSize().y / 5
    #define POS_Y_FIVE_2        window.getSize().x / 2, window.getSize().y / 5 * 2
    #define POS_Y_FIVE_3        window.getSize().x / 2, window.getSize().y / 5 * 3
    #define POS_Y_FIVE_4        window.getSize().x / 2, window.getSize().y / 5 * 4

    #define SCALE_1_NEGATIVE  (sf::Vector2f){-1.0f, 1.0f}
    #define SCALE_2_NEGATIVE  (sf::Vector2f){-2.0f, 2.0f}
    #define SCALE_3_NEGATIVE  (sf::Vector2f){-3.0f, 3.0f}
    #define SCALE_4_NEGATIVE  (sf::Vector2f){-4.0f, 4.0f}
    #define SCALE_5_NEGATIVE  (sf::Vector2f){-5.0f, 5.0f}
    #define SCALE_6_NEGATIVE  (sf::Vector2f){-6.0f, 6.0f}
    #define SCALE_7_NEGATIVE  (sf::Vector2f){-7.0f, 7.0f}
    #define SCALE_8_NEGATIVE  (sf::Vector2f){-8.0f, 8.0f}
    #define SCALE_9_NEGATIVE  (sf::Vector2f){-9.0f, 9.0f}
    #define SCALE_10_NEGATIVE (sf::Vector2f){-10.0f, 10.0f}

    #define SCALE_1          (sf::Vector2f){1.0f, 1.0f}
    #define SCALE_2          (sf::Vector2f){2.0f, 2.0f}
    #define SCALE_3          (sf::Vector2f){3.0f, 3.0f}
    #define SCALE_4          (sf::Vector2f){4.0f, 4.0f}
    #define SCALE_5          (sf::Vector2f){5.0f, 5.0f}
    #define SCALE_6          (sf::Vector2f){6.0f, 6.0f}
    #define SCALE_7          (sf::Vector2f){7.0f, 7.0f}
    #define SCALE_8          (sf::Vector2f){8.0f, 8.0f}
    #define SCALE_9          (sf::Vector2f){9.0f, 9.0f}
    #define SCALE_10         (sf::Vector2f){10.0f, 10.0f}

    #define SCALE_0_25       (sf::Vector2f){0.25f, 0.25f}
    #define SCALE_0_50       (sf::Vector2f){0.50f, 0.50f}
    #define SCALE_0_75       (sf::Vector2f){0.75f, 0.75f}

    #define OPACITY_0        (sf::Color){255, 255, 255, 0}
    #define OPACITY_50       (sf::Color){255, 255, 255, 128}
    #define OPACITY_100      (sf::Color){255, 255, 255, 255}

    #define TRANS_POS        (sf::Vector2f){0, 0}
    #define TRANS_SIZE       (sf::Vector2f){1920, 1080}
    #define TRANS_COLOR      (sf::Color){0, 0, 0, 255}

    #define TRANS_OFF           0
    #define TRANS_IN            1
    #define TRANS_OUT           2

    #define ELEM_BG_LEFT            (sf::IntRect){0, 4, 4, 1}
    #define ELEM_BG_RIGHT           (sf::IntRect){31, 4, 4, 1}
    #define ELEM_BG_TOP             (sf::IntRect){4, 0, 1, 4}
    #define ELEM_BG_BOTTOM          (sf::IntRect){4, 31, 1, 4}
    #define ELEM_BG_TOP_LEFT        (sf::IntRect){0, 0, 4, 4}
    #define ELEM_BG_TOP_RIGHT       (sf::IntRect){31, 0, 4, 4}
    #define ELEM_BG_BOTTOM_LEFT     (sf::IntRect){0, 31, 4, 4}
    #define ELEM_BG_BOTTOM_RIGHT    (sf::IntRect){31, 31, 4, 4}
    #define ELEM_BG_MIDDLE          (sf::IntRect){4, 4, 1, 1}

    #define TEXT_OUTLINE                3
    #define TEXT_SELECTED_COLOR         sf::Color(255, 138, 0)

    #define SET_TEXT_LEFT           0
    #define SET_TEXT_MID            1
    #define SET_TEXT_RIGHT          2

    #define WINDOW_MIDDLE           (sf::Vector2f){window.getSize().x / 2.0f, \
    window.getSize().y / 2.0f}
    #define WINDOW_MIDDLE_LEFT           (sf::Vector2f){window.getSize().x / 3.0f, \
    window.getSize().y / 2.0f}
    #define WINDOW_MIDDLE_RIGHT           (sf::Vector2f){window.getSize().x / 1.5f, \
    window.getSize().y / 2.0f}

void create_new_text(sf::Text &text, sf::Font &font, std::string str, int size, sf::Color color, sf::Vector2f pos, float angle, sf::Vector2f scale);
void create_new_sprite(sf::Sprite &sprite, sf::Texture &texture, sf::IntRect rect, sf::Vector2f pos, float angle, sf::Vector2f scale);
bool check_pos_mouse(sf::Vector2i &mouse, const sf::FloatRect &size, sf::RenderWindow &window);
bool is_key_pressed(int key, sf::Event &event);
void set_text_string(sf::Text &text, std::string &str, int position);
