#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

using namespace std;
using namespace sf;


void drawQuad(RenderWindow& window);

int main() {

RenderWindow window(VideoMode(610, 715, 32), "Morpion");
window.setFramerateLimit(30);

Game game(window);

while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();

    }
    window.clear(Color::White);
    drawQuad(window);
    window.display();
}
}


void drawQuad(RenderWindow& window) {
    RectangleShape quad[5];
    for (int i = 0 ; i < 3 ; i ++) {
        quad[i].setSize(Vector2f(610, 5));
    }
    for (int j = 3 ; j < 5 ; j++) {
        quad[j].setSize(Vector2f(5, 615));
    }
    quad[0].setPosition(0, 510);
    quad[1].setPosition(0, 310);
    quad[2].setPosition(0, 110);
    quad[3].setPosition(200, 110);
    quad[4].setPosition(405, 110);

    for (int i = 0 ; i <= 4 ; i++) {
        quad[i].setFillColor(Color::Black);
        window.draw(quad[i]);
    }
}
