
#include "game/main.hpp"

using namespace utils;
namespace Tank
{

void HUD::setAlive()
{
    name.setStyle(sf::Text::Style::Regular);
}

void HUD::setDead()
{
    name.setStyle(sf::Text::Style::StrikeThrough);
}

}
