
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

ButtonWrite::ButtonWrite()
{
    activated = false;
    new_digit = 0;
    str = "";
    only_digit = false;
}

ButtonWrite::~ButtonWrite()
{
}

void ButtonWrite::create(bool do_sprite, sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, bool do_text, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool digit)
{
    this->only_digit = digit;
    this->str = str;
    if (do_sprite) {
        sprite = new sf::Sprite();
        newSprite(*sprite, texture, rect, pos);
        sprite_rect = sprite_info;
    }
    if (do_text) {
        text = new sf::Text();
        newText(*text, font, this->str, size, pos);
        text_color = text_info;
    }
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void ButtonWrite::getRectColor(ButtonRect &rect)
{
    if (IS_TRUE(this->activated)) {
        rect = {
            sprite_rect.idle + sprite_rect.click,
            sprite_rect.hover + sprite_rect.click,
            sprite_rect.hover + sprite_rect.click,
        };
    } else {
        rect = {
            sprite_rect.idle,
            sprite_rect.hover,
            sprite_rect.hover,
        };
    }
}

void ButtonWrite::getEventMouse(sf::RenderWindow &window)
{
    ButtonRect rect;

    this->getRectColor(rect);
    this->getMousePosition(window, rect, text_color);
    this->getEventWrite();
}

void ButtonWrite::getEventMouse(sf::RenderWindow &window, sf::View &view)
{
    ButtonRect rect;

    this->getRectColor(rect);
    this->getMousePosition(window, rect, text_color);
    this->getEventWrite();
}

void ButtonWrite::getEventWrite()
{
    if (IS_TRUE(hold))
        return;

    if (IS_TRUE(this->hover)) {
        if (IS_TRUE(this->click)) {
            this->setActivation(true);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !IS_TRUE(click)) {
        this->setActivation(false);
    }
}

// ****************************************************************************
// ACTIVATION
// ****************************************************************************

void ButtonWrite::setActivation(bool value)
{
    activated = value;

    if (IS_DEFINED(sprite)) {
        sf::IntRect rect = sprite->getTextureRect();
        if (value) {
            rect.left = sprite_rect.idle + sprite_rect.click;
        } else {
            rect.left = sprite_rect.idle;
        }
        sprite->setTextureRect(rect);
    }
}

bool ButtonWrite::getActivation() const
{
    return activated;
}

// ****************************************************************************
// Write
// ****************************************************************************

void ButtonWrite::getEventKey(sf::Event &event, sf::String banned)
{
    if (!IS_TRUE(this->activated))
        return;

    if (event.type == sf::Event::TextEntered){

        for (size_t i = 0; i < banned.getSize(); i++) {
            if (event.text.unicode == banned[i]) {
                return;
            }
        }

        if (event.text.unicode == WRITE_DELETE) {
            if (IS_TRUE(only_digit))
                this->deleteDigit(false);
            else
                this->deleteChar(false);
        } else if (event.text.unicode == WRITE_CTRL_DELETE) {
            if (IS_TRUE(only_digit))
                this->deleteDigit(true);
            else
                this->deleteChar(true);
        } else {
            if (IS_TRUE(only_digit))
                this->addDigit(event.text.unicode);
            else
                this->addChar(event.text.unicode);
        }
        setTextString((*text), str, MID);
    }
}

void ButtonWrite::addChar(sf::Uint32 character)
{
    str += character;
}

void ButtonWrite::deleteChar(bool all)
{
    if (!IS_TRUE(str.isEmpty())) {
        if (IS_TRUE(all)) {
            this->str.clear();
        } else {
            str.erase(str.getSize() - 1, 1);
        }
    }
}

void ButtonWrite::addDigit(sf::Uint32 character)
{
    if (character < '0' || character > '9')
        return;
    if (str.getSize() < 9) {
        if (str == "0")
            str.clear();
        str += character;
    }
}

void ButtonWrite::deleteDigit(bool all)
{
    if (this->str.getSize() > 1 && !IS_TRUE(all)) {
        str.erase(str.getSize() - 1, 1);
    } else {
        this->str.clear();
        this->str = "0";
    }
}

bool ButtonWrite::hasPressedEnter()
{
    if (str.getSize() == 0)
        return false;

    if (str[str.getSize() - 1] == 13) {
        str.erase(str.getSize() - 1);
        return true;
    } else {
        return false;
    }
}

sf::String ButtonWrite::getString() const
{
    return str;
}

size_t ButtonWrite::getStringValue() const
{
    size_t nbr = std::stoull(str.toAnsiString());
    return nbr;
}

}
