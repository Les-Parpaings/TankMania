
#include "tankmania.hpp"
#include <array>

using namespace utils;
namespace Tank {

//-----------------------------------------------
//  OBB
//-----------------------------------------------

// Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
OrientedBoundingBox::OrientedBoundingBox(const sf::Sprite& sprite)
{
    auto transform = sprite.getTransform();
    auto local = sprite.getTextureRect();

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

bool Player::isColliding(sf::VertexArray &wall)
{
    auto OBB1 = OrientedBoundingBox(this->sprite);
    auto OBB2 = OrientedBoundingBox(wall);

    // Create the four distinct axes that are perpendicular to the edges of the sprite
    // std::array<sf::Vector2f, 4> axes = {
    //     sf::Vector2f{OBB1.points[1].x - OBB1.points[0].x, OBB1.points[1].y - OBB1.points[0].y},
    //     sf::Vector2f{OBB1.points[2].x - OBB1.points[1].x, OBB1.points[1].y - OBB1.points[2].y},
    //     sf::Vector2f{OBB2.points[1].x - OBB2.points[0].x, OBB2.points[1].y - OBB2.points[0].y},
    //     sf::Vector2f{OBB2.points[2].x - OBB2.points[1].x, OBB2.points[1].y - OBB2.points[2].y}
    // };
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
        // std::cout << "!((" << (minOBB2 < maxOBB1) << ") && (" << (maxOBB2 > minOBB1) << ")) ) == " << !((minOBB2 < maxOBB1) && (maxOBB2 > minOBB1)) << std::endl;;
        if ( !((minOBB2 < maxOBB1) && (maxOBB2 > minOBB1)) ) {
            return false;
        }
    }

    // auto bounds = sprite.getGlobalBounds();
    // std::cout << bounds.top << " >= " << wall[3].position.y;
    // if (bounds.top >= wall[3].position.y) {
    //     std::cout << "up" << std::endl;
    // } else {
    //     std::cout << "down" << std::endl;
    // }

    return true;
}

}
