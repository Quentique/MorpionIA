#include "startmenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

StartMenu::StartMenu(RenderWindow& gwindow) : quit(false), window(gwindow) {
if (!font.loadFromFile("comic.ttf"))
    cout << "ERROR DURING LOADING FONT" << endl;
}

void StartMenu::run() {
    window.create(VideoMode(610, 200), "MorpionIA");
    Text title;
    title.setFont(font);
    title.setCharacterSize(36);
    title.setString("Morpion");
    title.setColor(Color::Red);
    title.setPosition(window.getSize().x/2-title.getGlobalBounds().width/2, 10);
    Text one_player;
    Text two_player;
    one_player.setFont(font);
    two_player.setFont(font);
    one_player.setCharacterSize(24);
    two_player.setCharacterSize(24);
    one_player.setString("1 - 1 Joueur");
    two_player.setString("2 - 2 Joueurs");
    one_player.setPosition(20, 100);
    two_player.setPosition(20, 130);
    two_player.setColor(Color::Blue);
    one_player.setColor(Color::Blue);

    while(!quit) {

        window.clear(Color::White);
        window.draw(title);
        window.draw(one_player);
        window.draw(two_player);
        window.display();

        Event event;
        while(window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseMoved) {
                if (event.mouseMove.x > one_player.getGlobalBounds().left && event.mouseMove.x < (one_player.getGlobalBounds().left + one_player.getGlobalBounds().width) && event.mouseMove.y > one_player.getGlobalBounds().top && event.mouseMove.y < (one_player.getGlobalBounds().top + one_player.getGlobalBounds().height))
                {
                    one_player.setColor(Color::Magenta);
                } else { one_player.setColor(Color::Blue); }
                if (event.mouseMove.x > two_player.getGlobalBounds().left && event.mouseMove.x < (two_player.getGlobalBounds().left + two_player.getGlobalBounds().width) && event.mouseMove.y > two_player.getGlobalBounds().top && event.mouseMove.y < (two_player.getGlobalBounds().top + two_player.getGlobalBounds().height))
                {
                    two_player.setColor(Color::Magenta);
                } else { two_player.setColor(Color::Blue); }
            }
            if (event.type == Event::MouseButtonPressed){
                if (event.mouseButton.x > one_player.getGlobalBounds().left && event.mouseButton.x < (one_player.getGlobalBounds().left + one_player.getGlobalBounds().width) && event.mouseButton.y > one_player.getGlobalBounds().top && event.mouseButton.y < (one_player.getGlobalBounds().top + one_player.getGlobalBounds().height))
                {
                    number_players = 1;
                    quit = true;
                }
                if (event.mouseButton.x > two_player.getGlobalBounds().left && event.mouseButton.x < (two_player.getGlobalBounds().left + two_player.getGlobalBounds().width) && event.mouseButton.y > two_player.getGlobalBounds().top && event.mouseButton.y < (two_player.getGlobalBounds().top + two_player.getGlobalBounds().height))
                {
                    number_players = 2;
                    quit = true;
                }
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Num1 || Keyboard::Numpad1)
                {
                    number_players = 1;
                    quit = true;
                } else if (event.key.code == Keyboard::Num2 || Keyboard::Numpad2) {
                    number_players = 2;
                    quit = true;
                }
            }
        }
    }

    quit = false;


}
