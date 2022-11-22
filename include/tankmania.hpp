
#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    // #include <SFML/Network.hpp>

    #include <iostream>
    #include <vector>
    #include <list>

    #include "utils/utils.hpp"
    #include "game.hpp"

namespace Tank {

enum allPart {
    PART_MENU,
    PART_GAME
};

struct TankMania {
    int part;

    Game game;
};

int main_tankmania(utils::Utils &utils);

void create_all(TankMania &var, utils::Utils &utils);
void destroy_all(TankMania &var, utils::Utils &utils);
void draw(TankMania &var, utils::Utils &utils);
void get_event_all(TankMania &var, utils::Utils &utils);

void do_game(TankMania &var, utils::Utils &utils);
void get_event_game(Game &var, utils::Utils &utils);

}
