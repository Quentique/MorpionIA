#ifndef STARTMENU_HPP_INCLUDED
#define STARTMENU_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class StartMenu {

public:
    StartMenu(sf::RenderWindow& gwindow);
    void run();
    int number_players;
    std::string name_player1;
    std::string name_player2;

private:
    bool quit;
    sf::Font font;

};

#endif // STARTMENU_HPP_INCLUDED
