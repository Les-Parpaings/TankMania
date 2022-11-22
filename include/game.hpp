
#pragma once

    #include "maze.hpp"

namespace Tank {

class Player {
    public:
        Player();
        void create(utils::Utils &utils);
        void draw(sf::RenderWindow &window);
        void getEvent(utils::Utils &utils);
        ~Player();

    private:
        sf::Sprite sprite;
};

struct Game {
    Maze maze;
    std::list<Player> players;
};

}
