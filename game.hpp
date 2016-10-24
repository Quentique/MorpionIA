#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {

public:
    Game(sf::RenderWindow& windows);
    enum Case {CROSS, NOUGHT, EMPTY};

private:
    sf::RenderWindow& window;
    Case quad[3][3];
    Case turn;
};

#endif // GAME_HPP_INCLUDED
