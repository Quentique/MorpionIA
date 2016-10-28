#include "player.hpp"
#include <string>

using namespace std;

Player::Player(Case gistate) : state(gistate), name((gistate==CROSS)?"Joueur 1":"Joueur 2"), score(0), won_stroke(0), lost_stroke(0)
{
}

Player::Player(Case gistate, string given_name) : state(gistate), name(given_name), score(0), won_stroke(0), lost_stroke()
{
}

Case Player::getCase()
{
    return state;
}
string Player::getName()
{
    return name;
}
int Player::getScore()
{
    return score;
}
void Player::make_win()
{
    score += 50;
}

void Player::make_lose()
{
    score -= 50;
}
int Player::getWonStroke() { return won_stroke; }
int Player::getLostStroke() { return lost_stroke; }

Player& Player::operator++(){
    won_stroke++;
    return *this;
}
Player Player::operator++(int) {
    Player ply = *this;
    ++*this;
    return ply;
}
Player& Player::operator--() {
lost_stroke++;
return *this;
}
Player Player::operator--(int) {
Player ply = *this;
--*this;
return ply;
}
