
#include "game/main.hpp"

using namespace utils;
namespace Tank
{

HUD::HUD()
{
}

HUD::HUD(Utils &utils, sf::Vector2f pos, sf::String str)
{
    newSprite(background, TEXTURE_NONE, sf::IntRect(0, 0, 300, 150), pos, VECTOR_1, sf::Color(64, 64, 64));

    newSprite(icon, TEXTURE_NONE, sf::IntRect(0, 0, 50, 50), pos + sf::Vector2f(-110.0f, 35.0f), VECTOR_1, sf::Color::Blue);
    newText(name, FONT_UBUNTU_BOLD, str, 35, pos - sf::Vector2f(135.0f, 40.0f), 2.0f);
    name.setOrigin(0.0f, name.getOrigin().y);

    newSprite(kill_icon, I_ICON_KILL, R_ICON, pos + sf::Vector2f(-45.0f, 35.0f), VECTOR_0_33);
    newText(kill_text, FONT_UBUNTU_REGULAR, "0", 25, kill_icon.getPosition() + sf::Vector2f(20.0f, 0.0f), 1.0f, sf::Color::White);
    kill_text.setOrigin(0.0f, kill_text.getOrigin().y);

    newSprite(victory_icon, I_ICON_VICTORY, R_ICON, kill_icon.getPosition() + sf::Vector2f(100.0f, 0.0f), VECTOR_0_33);
    newText(victory_text, FONT_UBUNTU_REGULAR, "0", 25, victory_icon.getPosition() + sf::Vector2f(20.0f, 0.0f), 1.0f, sf::Color::White);
    victory_text.setOrigin(0.0f, victory_text.getOrigin().y);
}

HUD::~HUD()
{
}

void HUD::draw(sf::RenderWindow &window, int powerup)
{
    window.draw(background);

    if (powerup != NO_POWERUP)
        window.draw(icon);
    window.draw(name);

    window.draw(kill_icon);
    window.draw(kill_text);

    window.draw(victory_icon);
    window.draw(victory_text);
}

} // namespace Tank
