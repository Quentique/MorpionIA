#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <string>
#include "game.hpp"

class Player
{
public:
    Player(Game::Case gstate);
    Player(Game::Case gstate, std::string given_name);
    Game::Case getCase();
    void make_win();
    void make_lose();

private:
    std::string name;
    int score;
    Game::Case state;
};

#endif // PLAYER_HPP_INCLUDED
