
#include "game/main.hpp"

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  CREATION
//-----------------------------------------------

sf::VertexArray createVertices(int x, int y, int width, int height, sf::Color color)
{
    sf::VertexArray vertices(sf::Quads, 4);

    for (size_t i = 0; i < vertices.getVertexCount(); i++) {
        vertices[i].color = color;
        vertices[i].position = sf::Vector2f(x, y);
        if (i == 1 || i == 2)
            vertices[i].position.x += width;
        if (i >= 2)
            vertices[i].position.y += height;
    }

    return vertices;
}

void Maze::generateGraphics()
{
    floor = createVertices(WALL_X, WALL_Y, width * WALL_LENGHT, height * WALL_LENGHT, sf::Color(196, 196, 196));

    for (size_t i = 0; i < horizontal.size(); i++) {
        if (horizontal[i]) {
            walls.push_back(createVertices(WALL_X + ((i % width) * WALL_LENGHT), WALL_Y + ((i / width) * WALL_LENGHT), WALL_LENGHT + WALL_THICKNESS, WALL_THICKNESS, sf::Color::Black));
        }
    }

    for (size_t i = 0; i < vertical.size(); i++) {
        if (vertical[i]) {
            walls.push_back(createVertices(WALL_X + ((i % (width + 1)) * WALL_LENGHT), WALL_Y + ((i / (width + 1)) * WALL_LENGHT), WALL_THICKNESS, WALL_LENGHT + WALL_THICKNESS, sf::Color::Black));
        }
    }
}

//-----------------------------------------------
//  DRAWING
//-----------------------------------------------

void Maze::draw(sf::RenderWindow &window)
{
    window.draw(floor);
    for (auto &it : walls) {
        window.draw(it);
    }
}

//-----------------------------------------------
//  GET INFO
//-----------------------------------------------

Walls &Maze::getWalls()
{
    return walls;
}

}
