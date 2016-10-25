#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {

public:
    enum Case {CROSS, NOUGHT, EMPTY};

    Game(sf::RenderWindow& windows);

    void drawQuad();
    void drawPlay();
    void drawText();
    bool won();

private:
    sf::RenderWindow& window;

    Case quad[3][3];
    Case turn;

    sf::Font font;

    sf::Image crossI, noughtI, win_crossI, win_noughtI;
    sf::Texture *cross, *nought, *win_cross, *win_nought;
    sf::Sprite sprite_quad[3][3];
};

#endif // GAME_HPP_INCLUDED
