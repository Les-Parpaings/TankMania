
#pragma once

namespace utils {

    #define TEXT_SELECTED_COLOR         sf::Color(255, 128, 0)

typedef struct ButtonRect {
    int idle;
    int hover;
    int click;
} ButtonRect;

typedef struct ButtonColor {
    sf::Color idle;
    sf::Color hover;
    sf::Color click;
} ButtonColor;

    #define BUTTON_COLOR_DEFAULT    ButtonColor{sf::Color::White, sf::Color::White, sf::Color::White}
    #define BUTTON_COLOR_CLASSIC    ButtonColor{sf::Color::White, TEXT_SELECTED_COLOR, sf::Color::Yellow}

    #define NO_SPRITE       false, TEXTURE_NONE, sf::IntRect(), ButtonRect{0, 0, 0}
    #define NO_TEXT         false, FONT_NONE, "", 0, BUTTON_COLOR_DEFAULT

/// \brief Default class for button without graphics.
/// \deprecated This class is deprecated because it don't hold the creation of the sprite and the text
class SFML_DEPRECATED Button
{
    public:
        Button();

        virtual void draw(sf::RenderWindow &window, const sf::RenderStates &states = sf::RenderStates::Default);

        /// \brief Get if the mouse is touching the button and if the left button is pressed
        /// \param window the window used
        /// \param s_rect The rect info for the sprite
        /// \param t_color The color info for the text
        void getMousePosition(sf::RenderWindow &window, ButtonRect s_rect, ButtonColor t_color);
        /// \brief Get if the mouse is touching the button and if the left button is pressed
        /// \param window the window used
        /// \param view the view used to draw the button
        /// \param s_rect The rect info for the sprite
        /// \param t_color The color info for the text
        void getMousePosition(sf::RenderWindow &window, sf::View &view, ButtonRect s_rect, ButtonColor t_color);

        /// \return true if the mouse is touching the button else returns false
        bool isHovered() const;
        /// \return true if the mouse is clicking on the button else returns false
        bool isClicked(bool do_reset = true);
        /// \return true if you hold the button pressed on the button otherwhise returns false
        bool isHolding();
        bool isPressed(bool do_reset = true);
        /// \brief reset the state of the button
        /// \param graphic true to reset the sprite and the text
        void reset(bool graphic = false);

        /// \return Sprite used for the button
        sf::Sprite *getSprite();
        /// \return Text used for the button
        sf::Text *getText();


        /// \brief default destructor for classic button
        virtual ~Button();

    protected:
        // Event
        bool hover;
        bool click;
        bool hold;

        // Sprite
        sf::Sprite *sprite;
        ButtonRect sprite_rect;

        // Text
        sf::Text *text;
        ButtonColor text_color;

        void getEventButton(sf::RenderWindow &window, sf::Vector2f pos, ButtonRect s_rect, ButtonColor t_color);
};

class ButtonClick : public Button
{
    public:
        ButtonClick();

        void create(bool do_sprite, sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, bool do_text, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, animState anim_state, bool os);
        void getEvent(sf::RenderWindow &window);
        void getEvent(sf::RenderWindow &window, sf::View &view);

        void setAnimation(animState new_value);
        animState getAnimation() const;
        virtual void doAnimation();

        virtual ~ButtonClick();

    protected:
        // Animation
        sf::Clock clock;
        utils::animState anim_value;
        bool one_shot;

        virtual void getEventClick();
};

class ButtonIcon : public ButtonClick
{
    public:
        ButtonIcon();

        void create(sf::Texture &t_button, sf::IntRect r_button, ButtonRect info_button, sf::Texture &t_icon, sf::IntRect r_icon, sf::Font &font, sf::String str, int size, sf::Vector2f pos, animState anim_state, bool os);
        virtual void draw(sf::RenderWindow &window, const sf::RenderStates &states = sf::RenderStates::Default);

        virtual void doAnimation();

        virtual ~ButtonIcon();

    private:
        sf::Sprite icon;

        virtual void getEventClick();
};

    #define COLOR_OFF       {sf::Color(168, 168, 168), sf::Color(168, 168, 168), sf::Color::White}
    #define COLOR_ON        {sf::Color::White, sf::Color::White, sf::Color(168, 168, 168)};

class ButtonOnOff : public Button
{
    public:
        ButtonOnOff();
        void create(bool do_sprite, sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, bool do_text, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool activated);
        void getEvent(sf::RenderWindow &window, int *len = nullptr);
        void getEvent(sf::RenderWindow &window, sf::View &view, int *len = nullptr);
        void setActivation(bool value);
        bool getActivation() const;
        void setTextOnOff(sf::String off, sf::String on);
        virtual ~ButtonOnOff();

    private:
        bool activated;
        sf::String on;
        sf::String off;

        void getRectColor(ButtonRect &rect, ButtonColor &color);
        void getEventOnOff(sf::RenderWindow &window, int *len = nullptr);
};

    #define WRITE_DELETE          8
    #define WRITE_CTRL_DELETE     127
    #define WRITE_ENTER           13

class ButtonWrite : public Button
{
    public:
        ButtonWrite();
        void create(bool do_sprite, sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, bool do_text, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool digit);
        void getEventMouse(sf::RenderWindow &window);
        void getEventMouse(sf::RenderWindow &window, sf::View &view);
        void getEventKey(sf::Event &event, sf::String banned = "");
        void setActivation(bool value);
        bool getActivation() const;
        void addChar(sf::Uint32 character);
        void deleteChar(bool all);
        void addDigit(sf::Uint32 character);
        void deleteDigit(bool all);
        bool hasPressedEnter();
        sf::String getString() const;
        size_t getStringValue() const;
        virtual ~ButtonWrite();

    private:
        sf::String str;
        char new_digit;
        bool activated;
        bool only_digit;

        void getRectColor(ButtonRect &rect);
        void getEventWrite();
};


}; // namespace utils
