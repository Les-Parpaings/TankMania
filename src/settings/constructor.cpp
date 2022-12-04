
#include "settings.hpp"

namespace Tank {

PlayerSettings::PlayerSettings(int i)
{
    index = i;
    name = "Player " + std::to_string(index);
}

Settings::Settings()
{
    players_size = 2;
    for (int i = 0; i < players_size; i++) {
        list.push_back(PlayerSettings(i));
    }
}

}
