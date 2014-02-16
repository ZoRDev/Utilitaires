#include "Button.h"

Button::Button() : m_width(20), m_height(15), m_posX(0), m_posY(0), m_color(sf::Color(255, 255, 255)) {
    this->m_button.setPosition(m_posX, m_posY);
    this->m_button.setSize(sf::Vector2f(m_width, m_height));
    this->m_button.setFillColor(m_color);
}

Button::Button(int x, int y, const std::string &text, sf::Color color, int width, int height) : m_width(width), m_height(height), m_posX(x), m_posY(y), m_text(text), m_color(color) {
    this->m_button.setPosition(m_posX, m_posY);
    this->m_button.setSize(sf::Vector2f(m_width, m_height));
    this->m_button.setFillColor(m_color);

    this->m_finalText.setColor(m_characterColor);
    this->m_finalText.setFont(loadFont());
    this->m_finalText.setCharacterSize(12);
    this->m_finalText.setString(text);
    this->m_finalText.move(this->getPosX() + this->getWidth() / 2 - this->m_finalText.getCharacterSize() / 2, this->getPosY() + this->getHeight() / 2 - this->m_finalText.getCharacterSize() / 2);
}

int Button::getWidth() { return this->m_width; }

int Button::getHeight() { return this->m_height; }

int Button::getPosX() { return this->m_posX; }

int Button::getPosY() { return this->m_posY; }

sf::Color Button::getColor() { return this->m_color; }

sf::RectangleShape Button::getButton() { return this->m_button; }

sf::Text Button::getText() { return this->m_finalText; }

void Button::setWidth(int width) { this->m_width = width; this->m_button.setSize(sf::Vector2f(m_width, m_height)); }

void Button::setHeight(int height) { this->m_height = height; this->m_button.setSize(sf::Vector2f(m_width, m_height)); }

void Button::setPosX(int posX) { this->m_posX = posX; this->m_button.setPosition(m_posX, m_posY); }

void Button::setPosY(int posY) { this->m_posY = posY; this->m_button.setPosition(m_posX, m_posY); }

void Button::setColor(sf::Color color) { this->m_color = color; this->m_button.setFillColor(m_color); }

void Button::setText(std::string text) { this->m_text = text; }

void Button::setCharacterColor(sf::Color color) { this->m_characterColor = color; }
