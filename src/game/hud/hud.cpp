
#include "game/main.hpp"

using namespace utils;
namespace Tank
{

HUD::HUD()
{
}

HUD::HUD(Utils &utils, sf::Vector2f pos, sf::Color color)
{
    newSprite(background, I_HUD_BG, R_HUD_BG, pos, VECTOR_1);

    newSprite(icon, TEXTURE_NONE, R_POWERUPS, pos + sf::Vector2f(100.0f, -30.0f), sf::Vector2f(0.15f, 0.15f));
    newSprite(player, I_PLAYER, R_PLAYER, pos - sf::Vector2f(85.0f, 30.0f), VECTOR_1, color, 90.0f);

    newSprite(kill_icon, I_HUD_KILL, R_HUD_ICON, pos + sf::Vector2f(-100.0f, 30.0f), VECTOR_0_25);
    newText(kill_text, FONT_UBUNTU_REGULAR, "0", 25, kill_icon.getPosition() + sf::Vector2f(40.0f, 0.0f), 1.0f);
    kill_text.setOrigin(0.0f, kill_text.getOrigin().y);

    newSprite(victory_icon, I_HUD_VICTORY, R_HUD_ICON, kill_icon.getPosition() + sf::Vector2f(150.0f, 0.0f), VECTOR_0_25);
    newText(victory_text, FONT_UBUNTU_REGULAR, "0", 25, victory_icon.getPosition() + sf::Vector2f(40.0f, 0.0f), 1.0f);
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
    window.draw(player);

    window.draw(kill_icon);
    window.draw(kill_text);

    window.draw(victory_icon);
    window.draw(victory_text);
}

} // namespace Tank
