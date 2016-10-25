#include "player.hpp"
#include "game.hpp"
#include <string>

using namespace std;

Player::Player(Game::Case gstate) : state(gstate), name((state==CROSS)?"Joueur 1":"Joueur2")
{
}

Player::Player(Game::Case gstate, string given_name) : state(gstate), name(given_name)
{
}

Case Player::getCase()
{
    return state;
}

void Player::make_win()
{
    score += 50;
}

void Player::make_lose()
{
    score -= 50;
}
