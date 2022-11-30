
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// WINDOW
// ****************************************************************************

Utils::Utils()
{
    //Window
    settings.antialiasingLevel = 8;
    window.create(WINDOW_SIZE, WINDOW_NAME, sf::Style::Fullscreen, settings);
    icon.loadFromFile(PATH_ICON);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(WINDOW_FPS);
    exit = false;

    //Cursor
    if (HAS_CURSOR)
        window.setMouseCursorVisible(false);

    //Time
    std::srand((unsigned int)(std::time(nullptr)));
}

Utils::~Utils()
{
}

void Utils::clear(sf::Color color)
{
    window.clear(color);
}

void Utils::draw()
{
    transition.doTransition();
    transition.draw(window);

    transition_circle.doTransition();
    transition_circle.draw(window);

    shaders.setParameter();

    if (HAS_CURSOR) {
        cursor.setCursorPosition(window);
        cursor.draw(window);
    }

    window.display();
}

void Utils::getExitEvent()
{
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

}
