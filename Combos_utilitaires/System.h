#ifndef DEF_SYSTEM
#define DEF_SYSTEM

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "main.h"

class System {
    public:
        System();
        void calculateFPS(int *fps);
        void pause(sf::RenderWindow &window, sf::Event event, sf::RectangleShape background);

    private:
        sf::Clock m_time;
        int m_fps;
};

#endif //DEF_SYSTEM
