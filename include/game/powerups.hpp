
#pragma once

namespace Tank {

enum PowerupsList {
    NO_POWERUP,
    BIG,
    SHOTGUN,
    MINIGUN,
    BOMBE,
    LASER,
    CAMO,
    BOMBE_EXPLOSION
};

class Powerup {
    public:

        Powerup(utils::Utils &utils, sf::Vector2f pos);
        void draw(sf::RenderWindow &window);
        sf::Sprite &getSprite();
        int getType();
        bool isAnimationDone();
        void doAnimation();
        ~Powerup();

    private:
        sf::Sprite sprite;
        int type;

        bool anim_done;
        int rot_nbr;
        int rot_index;
};

}
