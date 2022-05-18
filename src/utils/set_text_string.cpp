/*
** EPITECH PROJECT, 2022
** util
** File description:
** src/util/util_set_text_string.c
*/

#include "utils.hpp"

//Set a string to an sfml text
void set_text_string(sf::Text &text, std::string &str, int position)
{
    text.setString(str);

    const sf::FloatRect rect = text.getGlobalBounds();;
    const sf::Vector2f origin = text.getOrigin();

    switch (position)
    {
        case SET_TEXT_LEFT:
            text.setOrigin(sf::Vector2f(0, origin.y));
            break;
        case SET_TEXT_MID:
            text.setOrigin(sf::Vector2f(rect.width / 2, origin.y));
            break;
        case SET_TEXT_RIGHT:
            text.setOrigin(sf::Vector2f(rect.width, origin.y));
            break;
    }
}
