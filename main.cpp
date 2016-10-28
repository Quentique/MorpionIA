#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"


using namespace std;
using namespace sf;

int main() {
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(610, 715, 32), "Morpion", Style::Default, settings);
    window.setFramerateLimit(20);

    Game game(window);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (!game.won()) {
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                game.play(event.mouseButton.x, event.mouseButton.y);
            }
            }
        }
        window.clear(Color::White);
        game.drawQuad();
        game.drawPlay();
        game.drawText();
        window.display();
    }
}
