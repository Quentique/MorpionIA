#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <string>
#include <iostream>
#include "case.hpp"

class Player
{

public:
    Player(Case gistate);
    Player(Case gistate, std::string given_name);
    Case getCase();
    std::string getName();
    int getScore();
    void make_win();
    void make_lose();

private:
    std::string name;
    int score;
    Case state;
};

#endif // PLAYER_HPP_INCLUDED
