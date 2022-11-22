
#include "tankmania.hpp"

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  CREATION
//-----------------------------------------------

sf::VertexArray createWall(int x, int y, int width, int height)
{
    sf::VertexArray vertices(sf::Quads, 4);

    vertices[0].position = sf::Vector2f(x        , y);
    vertices[1].position = sf::Vector2f(x + width, y);
    vertices[2].position = sf::Vector2f(x + width, y + height);
    vertices[3].position = sf::Vector2f(x        , y + height);

    return vertices;
}

void Maze::generateGraphics()
{
    for (int i = 0; i < horizontal.size(); i++) {
        if (horizontal[i]) {
            walls.push_back(createWall(WALL_X + ((i % width) * WALL_LENGHT), WALL_Y + ((i / width) * WALL_LENGHT), WALL_LENGHT + WALL_THICKNESS, WALL_THICKNESS));
        }
    }

    for (int i = 0; i < vertical.size(); i++) {
        if (vertical[i]) {
            walls.push_back(createWall(WALL_X + ((i % (width + 1)) * WALL_LENGHT), WALL_Y + ((i / (width + 1)) * WALL_LENGHT), WALL_THICKNESS, WALL_LENGHT + WALL_THICKNESS));
        }
    }
}

//-----------------------------------------------
//  DRAWING
//-----------------------------------------------

void Maze::draw(sf::RenderWindow &window)
{
    for (auto &it : walls) {
        window.draw(it);
    }
}

}
