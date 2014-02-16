#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "System.h"
#include "Button.h"
#include "main.h"

int main() {
    std::cout << "Your OS is " << getOsName() << std::endl;
    System gameSystem;

    sf::VideoMode clientVideoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(clientVideoMode.width/1.5, clientVideoMode.height/1.5, 32), "Utilitaires");

    Button button(0, 0, "test", sf::Color(255, 255, 255), window.getSize().x / 3, window.getSize().y / 11);
    button.setPosX(window.getSize().x / 2 - button.getWidth() / 2);
    button.setPosY(window.getSize().y / 2 - button.getHeight() / 2);

    sf::RectangleShape grey(sf::Vector2f(window.getSize().x, window.getSize().y));
    grey.setFillColor(sf::Color(225, 225, 225));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << "The window's size was modified. The width size is now " << event.size.width << " and the height size is now " << event.size.height << "." << std::endl;
                    break;
                case sf::Event::LostFocus:
                    gameSystem.pause(window, event, grey);
                    break;
                case sf::Event::TextEntered:
                    std::cout << "A character was entered : " << static_cast<char>(event.text.unicode) << std::endl;
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Escape:
                            gameSystem.pause(window, event, grey);
                            break;
                    }
            }
        }
        window.clear();
        window.draw(grey);
        window.draw(button.getButton());
        window.draw(button.getText());
        window.display();

        int fps; gameSystem.calculateFPS(&fps);

        if (fps == 0) {} else {
            std::cout << fps << " FPS." << std::endl;
        }
    }

    std::cout << std::endl << "End of program..." << std::endl << "... Success !";

    return EXIT_SUCCESS;
}

std::string getOsName() {
    #ifdef __APPLE__ || __MACH__
    return "Mac OSX";
    #elif _WIN64
    return "Windows";
    #elif _WIN32
    return "Windows";
    #elif __unix || __unix__
    return "Unix";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "unknown";
    #endif
}

sf::Font loadFont() {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        exit(EXIT_FAILURE);
    return font;
}
