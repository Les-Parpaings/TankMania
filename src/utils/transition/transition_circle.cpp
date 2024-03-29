
#include "utils/utils.hpp"
#include <functional>

namespace utils {

// ****************************************************************************
// Transition
// ****************************************************************************

TransitionCircle::TransitionCircle()
{
    circle.setRadius(1920.0f);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(0.0f);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(sf::Vector2f(WINDOW_SIZE.width / 2.0f, WINDOW_SIZE.height / 2.0f));
    circle.setOrigin(sf::Vector2f(circle.getLocalBounds().left + circle.getLocalBounds().width / 2.0f, circle.getLocalBounds().top + circle.getLocalBounds().height / 2.0f));
    circle.setPointCount(100);

    value = FADE_OFF;
}

TransitionCircle::~TransitionCircle()
{
}

void TransitionCircle::draw(sf::RenderWindow &window)
{
    window.draw(circle);
}

void TransitionCircle::doTransition()
{
    // if (value == FADE_DONE || value == FADE_OUT)
    //     return;

    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(5)) {

        float radius = circle.getRadius();
        if (value == FADE_IN) {
            radius -= TRANS_ADD * 3;
            if (radius <= 0.0f) {
                radius = 0.1f; // not zero because it become invisible
                value = FADE_DONE;
            }
        } else if (value == FADE_OUT) {
            radius += TRANS_ADD * 3;
            if (radius >= 1920.0f) {
                radius = 1920.0f;
                value = FADE_OFF;
            }
        }
        circle.setRadius(radius);
        circle.setOutlineThickness(1920.0f - radius);
        circle.setOrigin(sf::Vector2f(circle.getLocalBounds().left + circle.getLocalBounds().width / 2.0f, circle.getLocalBounds().top + circle.getLocalBounds().height / 2.0f));

        clock.restart();
    }
}

void TransitionCircle::setAnimValue(animState new_value)
{
    value = new_value;

    if (value == FADE_DONE) {
        circle.setOutlineThickness(1920.0f);
    } else if (value == FADE_OFF) {
        circle.setOutlineThickness(0.0f);
    }
}

animState TransitionCircle::getAnimValue() const
{
    return value;
}

}
