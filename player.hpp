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

    Player& operator--();
    Player operator--(int);

    Player(Case gistate);
    Player(Case gistate, std::string given_name);

    Case getCase();
    std::string getName();
    int getScore();
    int getWonStroke();
    int getLostStroke();

    void make_win();
    void make_lose();


private:
    std::string name;
    int score, won_stroke, lost_stroke;
    Case state;
};

#endif // PLAYER_HPP_INCLUDED
