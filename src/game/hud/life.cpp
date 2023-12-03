
#include "game/main.hpp"

using namespace utils;
namespace Tank
{

void HUD::setAlive()
{
    auto color = player.getColor();
    color.a = 255;
    player.setColor(color);
}

void HUD::setDead()
{
    auto color = player.getColor();
    color.a = 64;
    player.setColor(color);}

}
