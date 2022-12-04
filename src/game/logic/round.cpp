
#include "game/main.hpp"

using namespace utils;
namespace Tank {

void Game::startRound()
{
    int x = WALL_WIDTH;
    int y = WALL_HEIGHT;
    maze.generateNewMaze(x, y);

    for (auto &it : players)
        it.restart(Random::getRandom(x), Random::getRandom(y));
    projectile.clear();
    powerups.clear();
    powerups_clock.restart();
}

void Game::restartRound()
{
    for (auto &it : players) {
        if (it.isAlive()) {
            it.addVictory();
        }
    }

    startRound();
}

}
