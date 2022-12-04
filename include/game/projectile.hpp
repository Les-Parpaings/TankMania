
#pragma once

namespace Tank {

// Say Player exists without defining it.
class Player;

class Projectile
{
    public:
        Projectile();
        Projectile(Player *player, int powerup_type, sf::Vector2f pos, float angle);
        void draw(sf::RenderWindow &window);
        bool doMovement(std::list<sf::VertexArray> &walls);
        float getTime();
        sf::CircleShape &getCircle();
        bool isOwner(Player *player);
        Player *getOwner();
        int getPowerupType();
        ~Projectile();

    private:
        sf::CircleShape circle;
        sf::Clock clock;
        int powerup;
        Player *owner;

        void getNewRotation(sf::VertexArray &wall);
};

}
