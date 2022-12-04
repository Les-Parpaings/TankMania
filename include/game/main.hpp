

#pragma once

    // SFML Libs
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    // #include <SFML/Network.hpp>

    // C++ Libs
    #include <iostream>
    #include <vector>
    #include <list>
    #include <array>

    // TankMania Utils
    #include "utils/utils.hpp"
    #include "assets_list.hpp"
    #include "settings.hpp"

    // Current Part
    #include "game/maze.hpp"
    #include "game/player.hpp"
    #include "game/projectile.hpp"
    #include "game/powerups.hpp"

namespace Tank {

// Custom Variable Name
using Walls             = std::list<sf::VertexArray>;
using Projectiles       = std::list<Projectile>;
using Players           = std::list<Player>;
using Powerups          = std::list<Powerup>;

class OrientedBoundingBox
{
    public:
        OrientedBoundingBox();
        template <typename T>
        OrientedBoundingBox(const T &entity);
        // OrientedBoundingBox(const sf::Sprite &sprite);
        // OrientedBoundingBox(const sf::CircleShape &circle);
        OrientedBoundingBox(const sf::VertexArray &vertices);
        void projectOntoAxis(const sf::Vector2f& axis, float& min, float& max);
        ~OrientedBoundingBox();

        std::array<sf::Vector2f, 4> points;
};

struct Game
{
    // Variable
    Maze maze;

    std::list<Player> players;
    std::list<Projectile> projectile;
    std::list<Powerup> powerups;
    sf::Clock powerups_clock;

    sf::Clock clock_end;


    // Member
    Game(utils::Utils &utils, Settings &settings);
    void getEvent(utils::Utils &utils);
    void doLogic(utils::Utils &utils);
    void draw(utils::Utils &utils);
    ~Game();

    // Logic
    void restartRound();
    void startRound();
};

// ****************************************************************************
//  SHARED
// ****************************************************************************

// Collision
template <typename T, typename U>
bool isColliding(T &entity1, U &entity2);
bool isCircleColliding(sf::CircleShape &circle, const sf::FloatRect &rect);
// Calcul
float calculMove(float angle, float velocity);

bool moveForward(int index);
bool moveBackward(int index);
bool rotateForward(int index);
bool rotateBackward(int index);
bool shoot(int index, bool &can_shoot, int powerup, sf::Clock &minigun_clock);

}
