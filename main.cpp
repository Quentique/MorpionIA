#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

using namespace std;
using namespace sf;


void drawQuad(RenderWindow& window);

int main() {
ContextSettings settings;
settings.antialiasingLevel = 8;

RenderWindow window(VideoMode(610, 715, 32), "Morpion", Style::Default, settings);
window.setFramerateLimit(30);

Game game(window);

while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();

    }
    window.clear(Color::White);
    game.drawQuad();
    window.display();
}
}
