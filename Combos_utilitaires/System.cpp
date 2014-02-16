#include "System.h"

System::System() : m_fps(0) {}

void System::calculateFPS(int *fps) {
    if (m_time.getElapsedTime().asMilliseconds() >= 1000) {
        m_time.restart();
        *fps = m_fps; m_fps = 0;
    } else { m_fps++; *fps = 0; }
}

void System::pause(sf::RenderWindow &window, sf::Event event, sf::RectangleShape background) {
    std::cout << "Pause started." << std::endl;

    sf::Font font = loadFont();
    sf::Text pause("PAUSE", font, 75);
    pause.setColor(sf::Color(0, 0, 0, 200));
    pause.move(window.getSize().x / 2 - pause.getCharacterSize() * 1.5, window.getSize().y / 2 - pause.getCharacterSize());

    bool stop(false);
    while (window.waitEvent(event) && !stop) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            window.close();
        }
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Escape:
                        stop = true;
                        break;
                }
                break;
        }
        window.clear();
        window.draw(background);
        window.draw(pause);
        window.display();
    }
    std::cout << "Pause is finished." << std::endl;
}
