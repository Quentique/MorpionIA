#include "startmenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

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
                quit = true;
                number_players = -1;
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

    if (number_players != -1)
    quit = false;

    RectangleShape input1, input2, input3;
    Text p[5];
    int select = 1;

    for (int i = 0 ; i < 5 ; i++)
    {
        p[i].setCharacterSize(24);
        p[i].setFont(font);
    }
    p[0].setString("Joueur 1 :");
    p[1].setString("Joueur 2 :");
    p[0].setColor(Color::Blue);
    p[1].setColor(Color::Blue);
    p[0].setPosition(20, 100);
    p[1].setPosition(20, 150);
    input1.setOutlineColor(Color::Black);
    input2.setOutlineColor(Color::Black);
    input1.setOutlineThickness(2);
    input2.setOutlineThickness(2);
    p[2].setString("Joueur 1_");
    p[3].setString((number_players==1)?"IA":"Joueur 2");
    p[2].setColor(Color::Magenta);
    p[3].setColor(Color::Blue);
    input1.setSize(Vector2f(150, p[2].getGlobalBounds().height+7));
    input2.setSize(Vector2f(150, p[2].getGlobalBounds().height+7));
    input1.setPosition(p[1].getGlobalBounds().width + p[1].getPosition().x + 10, p[0].getGlobalBounds().top - 2);
    input2.setPosition(p[1].getGlobalBounds().width + p[1].getPosition().x + 10, p[1].getGlobalBounds().top - 2);
    input1.setFillColor(Color::Transparent);
    input2.setFillColor(Color::Transparent);
    p[2].setPosition(148, 100);
    p[3].setPosition(148, 152);
    p[4].setString("Valider");
    p[4].setColor(Color::Blue);
    input3.setFillColor(Color::Green);
    input3.setSize(Vector2f(150, 50));
    input3.setPosition(400, 112);
    p[4].setPosition(400-p[4].getGlobalBounds().width/2+input3.getGlobalBounds().width/2, 110+input3.getGlobalBounds().height/2-p[4].getGlobalBounds().height/2);


    Clock clock;
    while(!quit) {

        window.clear(Color::White);
        window.draw(title);
        window.draw(p[0]);
        window.draw(p[1]);
        window.draw(p[2]);
        window.draw(p[3]);
        window.draw(input1);
        window.draw(input2);
        window.draw(input3);
        window.draw(p[4]);
        window.display();

        Event event;
        while(window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                quit = true;
                number_players = -1;

                } else if (event.type == Event::MouseButtonPressed && event.mouseButton.x > input3.getGlobalBounds().left && event.mouseButton.x < input3.getGlobalBounds().left + input3.getGlobalBounds().width && event.mouseButton.y < input3.getGlobalBounds().top + input3.getGlobalBounds().height && event.mouseButton.y > input3.getGlobalBounds().top) {

                    quit = true;
                    name_player1 = p[2].getString();
                    name_player2 = p[3].getString();

                    if (name_player1.length() == 0 || (name_player1.length() == 1 && name_player1[name_player1.length()-1] == '_')){
                        name_player1 = "Joueur 1";
                    } else if(name_player1[name_player1.length()-1] == '_'){
                        name_player1.resize(name_player1.length()-1);
                    }

                    if (name_player2.length() == 0 || (name_player2.length() == 1 && name_player2[name_player2.length()-1] == '_')) {
                        name_player2 = "Joueur 2";
                    } else if (name_player2[name_player2.length()-1] == '_') {
                        name_player2.resize(name_player2.length()-1);
                    }

            } else if (event.type == Event::MouseButtonPressed && number_players == 2) {

                if (event.mouseButton.x > input1.getGlobalBounds().left && event.mouseButton.x < input1.getGlobalBounds().left + input1.getGlobalBounds().width && event.mouseButton.y < input1.getGlobalBounds().top + input1.getGlobalBounds().height && event.mouseButton.y > input1.getGlobalBounds().top) {
                    select = 1;

                    p[2].setColor(Color::Magenta);
                    p[3].setColor(Color::Blue);

                    string st = p[3].getString();

                    if (st[st.length()-1] == '_')
                    {
                        p[3].setString(st.substr(0, st.length()-1));
                    }

                } else if (event.mouseButton.x > input2.getGlobalBounds().left && event.mouseButton.x < input2.getGlobalBounds().left + input2.getGlobalBounds().width && event.mouseButton.y < input2.getGlobalBounds().top + input2.getGlobalBounds().height && event.mouseButton.y > input2.getGlobalBounds().top) {
                    select = 2;
                    p[2].setColor(Color::Blue);
                    p[3].setColor(Color::Magenta);
                    string st = p[2].getString();
                    if (st[st.length()-1] == '_')
                    {
                        p[2].setString(st.substr(0, st.length()-1));
                    }
                }

            } else if (event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace) {
                string fr = p[select+1].getString();

                if (fr.length() > 0) {
                    if (fr[fr.length()-1] == '_')
                    {
                        if (fr.length() == 1)
                        {
                            fr = "";
                        } else {
                            fr.resize(fr.length()-2);
                        }
                    } else {
                        fr.resize(fr.length()-1);
                    }
                    p[select+1].setString(fr);
                }

            } else if (event.type == Event::TextEntered && event.text.unicode != 8 && event.text.unicode != 13) {
                string fr = p[select+1].getString();

                if (fr[fr.length()-1] == '_') {
                    fr[fr.length()-1] = static_cast<char>(event.text.unicode);
                } else {
                    fr += static_cast<char>(event.text.unicode);
                }
                p[select+1].setString(fr);

            } else if (event.type == Event::MouseMoved) {

                if(event.mouseMove.x > input3.getGlobalBounds().left && event.mouseMove.x < (input3.getGlobalBounds().left + input3.getGlobalBounds().width) && event.mouseMove.y > input3.getGlobalBounds().top && event.mouseMove.y < (input3.getGlobalBounds().top + input3.getGlobalBounds().height)) {
                    input3.setFillColor(Color(0, 242, 0));
                } else {
                    input3.setFillColor(Color::Green);
                }
            }
        }

        if (clock.getElapsedTime() > seconds(0.5))
        {
            string st = p[select+1].getString();
            if (st[st.length()-1] == '_')
            {
                p[select+1].setString(st.substr(0, st.length()-1));
                clock.restart();
            } else {
                p[select+1].setString(st + "_");
                clock.restart();
            }
        }

    }

}
