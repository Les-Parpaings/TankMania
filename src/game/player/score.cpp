
#include "game/main.hpp"

using namespace utils;
namespace Tank {

// ****************************************************************************
//  KILL
// ****************************************************************************

void Player::addKill()
{
    kill++;
    hud.setTextKill(kill);
}

void Player::setKill(int score)
{
    kill = score;
    hud.setTextKill(kill);
}

int Player::getKill() const
{
    return kill;
}

// ****************************************************************************
//  VICTORY
// ****************************************************************************

void Player::addVictory()
{
    victory++;
    hud.setTextVictory(victory);
}

void Player::setVictory(int score)
{
    victory = score;
    hud.setTextVictory(victory);
}

int Player::getVictory() const
{
    return victory;
}

}
