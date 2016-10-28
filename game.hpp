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
    void drawRestart();
    bool won();
    bool play_finished();
    void draw(int gx, int gy, Case gstate);
    void play(int mouse_x, int mouse_y);
    void cancel(int gx, int gy);
    std::array<int, 2> getCase(int mouse_x, int mouse_y);
    void reset();

    static std::string IntToString(int number);

private:
    sf::RenderWindow& window;

    Player *player1, *player2;

    Case quad[3][3];
    Case turn;

    sf::Font font;

    sf::Image crossI, noughtI;
    sf::Texture *cross, *nought, *empty_text;
    sf::Sprite sprite_quad[3][3];

    bool end_play, null;
};

#endif // GAME_HPP_INCLUDED
