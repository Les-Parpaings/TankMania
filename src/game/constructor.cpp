
#include "game/main.hpp"

using namespace utils;
namespace Tank {

Game::Game(Utils &utils, Settings &settings)
{
    for (int i = 0; i < settings.players_size; i++) {
        players.push_back(Player(utils, settings.list[i]));
    }

    startRound();
}

}
