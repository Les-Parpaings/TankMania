
#pragma once

namespace Tank {

    // ************************************************************************
    // IMAGE
    // ************************************************************************

    #define I_ICON_KILL                 utils.textures.getTexture("icon_skull")
    #define I_ICON_VICTORY              utils.textures.getTexture("icon_skull")

    #define R_ICON                      sf::IntRect( 0, 0, 100, 100)

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
