
#include "game/main.hpp"

using namespace utils;
namespace Tank {

void do_logic_player(Player &player, Game &var, Utils &utils)
{
    if (!player.isAlive())
        return;

    player.doMovement(var.maze.getWalls());
    player.doShooting(utils, var.projectile);

    for (auto it = var.projectile.begin(); it != var.projectile.end(); it++) {
        if (player.touchedProjectile(*it)) {
            it = var.projectile.erase(it);
            if (Player::remaning > 0) {
                var.clock_end.restart();
            }
            break;
        }
    }

    for (auto it = var.powerups.begin(); it != var.powerups.end(); it++) {
        if (!it->isAnimationDone())
            continue;

        if (player.touchedPowerup(*it)) {
            it = var.powerups.erase(it);
            break;
        }
    }
}

void do_logic_projectile(Projectiles &list, Walls &walls)
{
    for (auto it = list.begin(); it != list.end(); it++) {
        bool bombe = it->doMovement(walls);

        if (bombe) {
            auto pos = it->getCircle().getPosition();
            auto player = it->getOwner();
            it = list.erase(it);
            for (int i = 0; i < 50; i++) {
                it = list.insert(list.end(), Projectile(player, BOMBE_EXPLOSION, pos, Random::getRandom(360)));
            }
            continue;
        }

        float time = it->getTime();
        float limit = (it->getPowerupType() == PowerupsList::SHOTGUN) ? 0.5f : 10.0f;

        if (time >= limit) {
            it = list.erase(it);
        } else if (time >= limit - 0.5f) {
            int alpha = (limit - time) * 512.0f;
            it->getCircle().setFillColor(sf::Color(0, 0, 0, alpha));
        }
    }
}

void do_logic_powerup(Powerups &list, sf::Clock &clock, Maze &maze, Utils &utils)
{
    // Animation
    for (auto it = list.begin(); it != list.end(); it++) {
        if (!it->isAnimationDone()) {
            it->doAnimation();
        }
    }

    // Creation
    if (clock.getElapsedTime().asSeconds() >= 1.0f) {
        sf::Vector2f size = maze.getSize();
        list.push_back(Powerup(utils, sf::Vector2f(Random::getRandomInRange(1, (int)size.x) * 100.0f - 10.0f, Random::getRandomInRange(1, (int)size.y) * 100.0f - 10.0f)));
        clock.restart();
    }
}

void Game::doLogic(Utils &utils)
{
    for (auto &it : players)
        do_logic_player(it, *this, utils);
    do_logic_projectile(projectile, maze.getWalls());
    do_logic_powerup(powerups, powerups_clock, maze, utils);

    // Check how many players are alive left
    if (Player::remaning <= 1 && clock_end.getElapsedTime().asSeconds() >= 5.0f) {
        restartRound();
    }
}

}
