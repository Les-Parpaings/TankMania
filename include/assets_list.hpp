
#pragma once

namespace Tank {

    // ************************************************************************
    // IMAGE
    // ************************************************************************

    #define I_PLAYER                    utils.textures.getTexture("player")

    #define I_POWERUP_BIG               utils.textures.getTexture("powerups/big")
    #define I_POWERUP_BOMB              utils.textures.getTexture("powerups/bomb")
    #define I_POWERUP_CAMO              utils.textures.getTexture("powerups/camo")
    #define I_POWERUP_MINIGUN           utils.textures.getTexture("powerups/minigun")
    #define I_POWERUP_SHOTGUN           utils.textures.getTexture("powerups/shotgun")

    #define I_HUD_BG                    utils.textures.getTexture("HUD/scoreboard")
    #define I_HUD_KILL                  utils.textures.getTexture("HUD/icon_kill")
    #define I_HUD_VICTORY               utils.textures.getTexture("HUD/icon_win")


    #define R_PLAYER                    sf::IntRect(0, 0,  34, 68)

    #define R_POWERUPS                  sf::IntRect(0, 0, 256, 256)

    #define R_HUD_BG                    sf::IntRect(0, 0, 300, 150)
    #define R_HUD_ICON                  sf::IntRect(0, 0, 200, 200)


    #define S_PLAYER                    sf::Vector2f(0.64f, 0.64f)
    #define S_POWERUPS                  sf::Vector2f(0.20f, 0.20f)

    // ************************************************************************
    // FONT
    // ************************************************************************

    #define FONT_UBUNTU_BOLD            utils.fonts.getFont("ubuntu_bold")
    #define FONT_UBUNTU_REGULAR         utils.fonts.getFont("ubuntu_regular")
    #define FONT_UBUNTU_LIGHT           utils.fonts.getFont("ubuntu_light")

    // ************************************************************************
    // SOUND
    // ************************************************************************

    // #define SOUND_EXAMPLE            utils.sounds.getSound("dir\\sound")

    // ************************************************************************
    // MUSIC
    // ************************************************************************

    // #define MUSIC_EXAMPLE            "dir\\music"

    // ************************************************************************
    // SHADER
    // ************************************************************************

    // #define SHADER_EXAMPLE           &utils.fonts.getShader("dir\\shader")

    // ************************************************************************
    // DATA
    // ************************************************************************

    // #define PATH_EXAMPLE                "assets\\data\\dir\\file.txt"
    // #define DIR_EXAMPLE                 "assets\\data\\dir\\"

}
