
#pragma once

    #include <SFML/Graphics.hpp>
    #include <vector>

namespace Tank {

struct PlayerSettings {
    int index;
    sf::String name;

    PlayerSettings(int i);
    ~PlayerSettings();
};

struct Settings {

    int players_size;
    std::vector<PlayerSettings> list;

    Settings();
    ~Settings();
};

}
