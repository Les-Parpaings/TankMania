
#include "game/main.hpp"
#include <array>

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  OBB
//-----------------------------------------------

// Default constructor
OrientedBoundingBox::OrientedBoundingBox()
{
    for (auto &it : points) {
        it = sf::Vector2f(0.0f, 0.0f);
    }
}

// Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
template <typename T>
OrientedBoundingBox::OrientedBoundingBox(const T &entity)
{
    auto transform = entity.getTransform();
    auto local = entity.getLocalBounds();

    points[0] = transform.transformPoint(0.f,         0.f);
    points[1] = transform.transformPoint(local.width, 0.f);
    points[2] = transform.transformPoint(local.width, local.height);
    points[3] = transform.transformPoint(0.f,         local.height);
}

// Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
OrientedBoundingBox::OrientedBoundingBox(const sf::VertexArray &vertices)
{
    for (size_t i = 0; i < points.size(); i++)
        points[i] = vertices[i].position;
}

// Project all four points of the OBB onto the given axis and return the dot products of the two outermost points
void OrientedBoundingBox::projectOntoAxis(const sf::Vector2f& axis, float& min, float& max)
{
    min = (points[0].x * axis.x + points[0].y * axis.y);
    max = min;
    for (int j = 1; j < points.size(); ++j) {
        auto projection = points[j].x * axis.x + points[j].y * axis.y;
        if (projection < min)
            min = projection;
        if (projection > max)
            max = projection;
    }
}

OrientedBoundingBox::~OrientedBoundingBox()
{
}

//-----------------------------------------------
//  LOGIC
//-----------------------------------------------

template bool isColliding(sf::Sprite &, sf::VertexArray &);
template bool isColliding(sf::Sprite &, sf::Sprite &);
template bool isColliding(sf::CircleShape &, sf::VertexArray &);
template bool isColliding(sf::CircleShape &, sf::Sprite &);

template <typename T, typename U>
bool isColliding(T &entity1, U &entity2)
{
    auto OBB1 = OrientedBoundingBox(entity1);
    auto OBB2 = OrientedBoundingBox(entity2);

    // Create the four distinct axes that are perpendicular to the edges of the sprite
    std::array<sf::Vector2f, 4> axes = {
        sf::Vector2f{OBB1.points[1].x - OBB1.points[0].x, OBB1.points[1].y - OBB1.points[0].y},
        sf::Vector2f{OBB1.points[1].x - OBB1.points[2].x, OBB1.points[1].y - OBB1.points[2].y},
        sf::Vector2f{OBB2.points[0].x - OBB2.points[3].x, OBB2.points[0].y - OBB2.points[3].y},
        sf::Vector2f{OBB2.points[0].x - OBB2.points[1].x, OBB2.points[0].y - OBB2.points[1].y}
    };

    for (auto &axis : axes) {
        float minOBB1, maxOBB1, minOBB2, maxOBB2;

        // Project the points of both OBBs onto the axis ...
        OBB1.projectOntoAxis(axis, minOBB1, maxOBB1);
        OBB2.projectOntoAxis(axis, minOBB2, maxOBB2);

        // true if there is no collision between the 2 axis, otherwise we check the others axes or end the loop
        if ( !((minOBB2 < maxOBB1) && (maxOBB2 > minOBB1)) ) {
            return false;
        }
    }

    return true;
}

bool isCircleColliding(sf::CircleShape &circle, const sf::FloatRect &rect)
{
    for (size_t i = 0; i < circle.getPointCount(); i++) {

        sf::Vector2f point = circle.getPoint(i);
        point.x += circle.getGlobalBounds().left;
        point.y += circle.getGlobalBounds().top;

        if (point.x >= rect.left && point.x <= rect.left + rect.width
         && point.y >= rect.top && point.y <= rect.top + rect.height) {
            return true;
        }
    }
    return false;
}

}
