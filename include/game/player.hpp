

#pragma once

    #include "game/projectile.hpp"
    #include "game/powerups.hpp"

namespace Tank {

class HUD
{
    public:
        HUD();
        HUD(utils::Utils &utils, sf::Vector2f pos, sf::Color color);
        void draw(sf::RenderWindow &window, int powerup);
        void setPowerup(const sf::Texture *texture);
        void setTextKill(int score);
        void setTextVictory(int score);
        void setAlive();
        void setDead();
        ~HUD();

    private:
        sf::Sprite background;

        sf::Sprite icon;
        sf::Sprite player;

        sf::Sprite kill_icon;
        sf::Text kill_text;

        sf::Sprite victory_icon;
        sf::Text victory_text;
};

class Player {
    public:

        static int remaning;

        Player();
        Player(utils::Utils &utils, PlayerSettings &settings);
        void draw(sf::RenderWindow &window);
        void doShooting(utils::Utils &utils, std::list<Projectile> &list);
        void doMovement(std::list<sf::VertexArray> &walls);
        bool touchedProjectile(Projectile &projectile);
        bool touchedPowerup(Powerup &powerup);
        void restart(int x, int y);
        bool isAlive();

        void addKill();
        void addVictory();
        void setKill(int score);
        void setVictory(int score);
        int getKill() const;
        int getVictory() const;

        ~Player();

    private:
        sf::Sprite sprite;
        sf::BlendMode blend;
        float speed;
        bool alive;
        int powerup;
        int index;

        bool can_shoot;
        sf::Clock minigun_clock;
        sf::Clock camo_clock;

        HUD hud;
        int kill;
        int victory;


        void checkOneMovement(std::list<sf::VertexArray> &walls, directions index);
        void checkOneRotation(std::list<sf::VertexArray> &walls, float angle);
        void launchProjectile(std::list<Projectile> &list);

};

}
