
#include "utils/utils.hpp"

namespace utils {

ButtonIcon::ButtonIcon()
{

}

ButtonIcon::~ButtonIcon()
{

}

void ButtonIcon::create(sf::Texture &t_button, sf::IntRect r_button, ButtonRect info_button, sf::Texture &t_icon, sf::IntRect r_icon, sf::Font &font, sf::String str, int size, sf::Vector2f pos, animState anim_state, bool os)
{
    sprite = new sf::Sprite();
    newSprite(*sprite, t_button, r_button, pos);
    sprite_rect = info_button;

    text = new sf::Text();
    newText(*text, font, str, size, pos);
    text_color = BUTTON_COLOR_DEFAULT;
    text->setPosition(text->getPosition().x, sprite->getGlobalBounds().top + sprite->getGlobalBounds().height + text->getGlobalBounds().height);
    text->setFillColor(sf::Color::Transparent);
    text->setOutlineColor(sf::Color::Transparent);

    newSprite(icon, t_icon, r_icon, pos);

    this->setAnimation(anim_state);
    this->one_shot = os;
}

void ButtonIcon::draw(sf::RenderWindow &window, const sf::RenderStates &states)
{
    sf::RenderStates renderStates;
    if (hover) {
        renderStates = states;
    } else {
        renderStates = sf::RenderStates::Default;
    }

    window.draw(*sprite, renderStates);
    window.draw(icon, renderStates);
    window.draw(*text, renderStates);
}

void ButtonIcon::getEventClick()
{
    if (IS_TRUE(hover) && anim_value == FADE_DONE) {
        text->setFillColor(sf::Color::White);
        text->setOutlineColor(sf::Color::Black);
    } else {
        text->setFillColor(sf::Color::Transparent);
        text->setOutlineColor(sf::Color::Transparent);
    }

    if (IS_TRUE(click) && IS_TRUE(one_shot)) {
        setAnimation(FADE_OUT);
    }
}


void ButtonIcon::doAnimation()
{
    if (anim_value == FADE_DONE || anim_value == FADE_OFF)
        return;

    float scale = sprite->getScale().x;
    float scale_init = scale;

    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(1)) {
        if (anim_value == FADE_IN) {
            scale += 0.10f;
            if (scale >= 1.0f) {
                this->setAnimation(FADE_DONE);
            }
        }
        if (anim_value == FADE_OUT) {
            scale -= 0.10f;
            if (scale <= 0.0f) {
                this->setAnimation(FADE_OFF);
            }
        }

        sprite->setScale(scale, scale);
        scale = (scale * icon.getScale().x) / scale_init;
        icon.setScale(scale, scale);

        clock.restart();
    }
}

}
