#include "game.hpp"

using namespace sf;

Game::Game(RenderWindow& windows) : window(windows), turn(CROSS)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; i < 3 ; i++)
        {
            quad[i][j] = EMPTY;
        }
    }
}
