
#include "game/main.hpp"

using namespace utils;
namespace Tank
{

void HUD::setPowerup(const sf::Texture *texture)
{
    icon.setTexture(*texture);
}

void HUD::setTextKill(int score)
{
    setTextString(kill_text, std::to_string(score), TextPosition::LEFT);
}

void HUD::setTextVictory(int score)
{
    setTextString(victory_text, std::to_string(score), TextPosition::LEFT);
}

}
