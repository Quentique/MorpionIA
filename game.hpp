#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class Game {

public:

    Game(sf::RenderWindow& windows);

    void drawQuad();
    void drawPlay();
    void drawText();
    bool won();
    void play(int gx, int gy, Case gstate);
    void cancel(int gx, int gy);
    std::array<int, 2> getCase(int mouse_x, int mouse_y);

    static std::string IntToString(int number);

private:
    sf::RenderWindow& window;

    Player *player1, *player2;

    Case quad[3][3];
    Case turn;

    sf::Font font;

    sf::Image crossI, noughtI, win_crossI, win_noughtI;
    sf::Texture *cross, *nought, *win_cross, *win_nought;
    sf::Sprite sprite_quad[3][3];
};

#endif // GAME_HPP_INCLUDED
