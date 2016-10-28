#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <string>
#include <iostream>
#include "case.hpp"

class Player
{

public:
    Player& operator++();
    Player operator++(int);

    Player(Case gistate);
    Player(Case gistate, std::string given_name);

    Case getCase();
    std::string getName();
    int getScore();
    int getPlayedStroke();

    void make_win();
    void make_lose(int adv);


private:
    std::string name;
    int score, played_stroke;
    Case state;
};

#endif // PLAYER_HPP_INCLUDED
