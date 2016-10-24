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

void Game::drawQuad() {
    RectangleShape quad[5];
    for (int i = 0 ; i < 3 ; i ++) {
        quad[i].setSize(Vector2f(610, 5));
    }
    for (int j = 3 ; j < 5 ; j++) {
        quad[j].setSize(Vector2f(5, 615));
    }
    quad[0].setPosition(0, 510);
    quad[1].setPosition(0, 310);
    quad[2].setPosition(0, 110);
    quad[3].setPosition(200, 110);
    quad[4].setPosition(405, 110);

    for (int i = 0 ; i <= 4 ; i++) {
        quad[i].setFillColor(Color::Black);
        window.draw(quad[i]);
    }
}
