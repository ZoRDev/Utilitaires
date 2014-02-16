#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "../main.h"

class Button {
    public:
        Button();
        Button(int x, int y, const std::string &text, const sf::Color color, int width, int heigth);
        int getWidth();
        int getHeight();
        int getPosX();
        int getPosY();
        sf::Color getColor();
        sf::RectangleShape getButton();
        sf::Text getText();
        void setWidth(int width);
        void setHeight(int height);
        void setPosX(int posX);
        void setPosY(int posY);
        void setColor(sf::Color color);
        void setText(std::string text);
        void setCharacterColor(sf::Color color);
    private:
        int m_width;
        int m_height;
        int m_posX;
        int m_posY;
        sf::Color m_color;
        std::string m_text;
        sf::RectangleShape m_button;
        sf::Text m_finalText;
        sf::Color m_characterColor;
};

#endif //DEF_BUTTON
