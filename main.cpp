#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {

RenderWindow window(VideoMode(600, 700, 32), "Morpion");

while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();

    }
    window.clear(Color::White);
    window.display();
}


}
