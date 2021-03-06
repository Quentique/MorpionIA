#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "startmenu.hpp"


using namespace std;
using namespace sf;

int main() {
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(610, 715, 32), "Morpion", Style::Default, settings);
    window.setFramerateLimit(20);

    StartMenu menu(window);
    menu.run();

    if (menu.number_players != -1)
    window.create(VideoMode(610, 715, 32), "Morpion", Style::Default, settings);


    Game game(window, menu.number_players, menu.name_player1, menu.name_player2);
    bool once = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (!game.play_finished()) {
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                game.play(event.mouseButton.x, event.mouseButton.y);
            }
            }
            else {

                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::N)
                    {
                        window.close();
                    } else if (event.key.code == Keyboard::O) {
                        game.reset();
                        once = false;
                    }
                }
            }
        }

        window.clear(Color::White);
        game.drawText();

        if (!game.play_finished()) {
            game.drawQuad();
            game.drawPlay();
        }
        else {
            if(!once) {
                game.drawQuad();
            game.drawPlay();
            window.display();
            sleep(seconds(2));
            once = true;
            window.clear();
            }

            game.drawRestart();
        }

        window.display();
    }
}
