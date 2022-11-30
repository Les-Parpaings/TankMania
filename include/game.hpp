
#pragma once

    #include "maze.hpp"
    #include <array>

namespace Tank {

class OrientedBoundingBox
{
    public:
        OrientedBoundingBox(const sf::Sprite& sprite);
        OrientedBoundingBox(const sf::VertexArray &vertices);
        void projectOntoAxis(const sf::Vector2f& axis, float& min, float& max);
        ~OrientedBoundingBox();

        std::array<sf::Vector2f, 4> points;
};

class Player {
    public:
        Player();
        void create(utils::Utils &utils);
        void draw(sf::RenderWindow &window);
        void getEvent();
        void doMovement(std::list<sf::VertexArray> &walls);
        bool isColliding(sf::VertexArray &wall);
        ~Player();

    private:
        sf::Sprite sprite;
        sf::Sprite line;
        sf::VertexArray test;

        void checkOneMovement(std::list<sf::VertexArray> &walls, directions index);
        void checkOneRotation(std::list<sf::VertexArray> &walls, float angle);
};

struct Game {
    Maze maze;
    Player players;
};

}
