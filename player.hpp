#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <string>
#include "game.hpp"

class Player
{
public:
    Player(Game::Case gstate);
    Player(Game::Case gstate, std::string given_name);

private:
    std::string name;
    int score;
    Game::Case state;
};

#endif // PLAYER_HPP_INCLUDED
