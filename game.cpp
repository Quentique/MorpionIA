#include "game.hpp"

using namespace sf;
using namespace std;

Game::Game(RenderWindow& windows) : window(windows), turn(CROSS)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; i < 3 ; i++)
        {
            quad[i][j] = EMPTY;
        }
    }


    if (!crossI.loadFromFile("x.bmp") || !noughtI.loadFromFile("o.bmp"))
        cout << "FATAL ERROR" << endl;

    crossI.createMaskFromColor(Color::Black);
    noughtI.createMaskFromColor(Color::Black);

    cross = new Texture();
    nought = new Texture();

    cross->loadFromImage(crossI, IntRect());
    nought->loadFromImage(noughtI);

    cross->setSmooth(true);
    nought->setSmooth(true);
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

    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++) {
            sprite_quad[i][j].setPosition(i*200, 110+j*200);
            sprite_quad[i][j].setScale(1.3333f, 1.3333f);
        }
    }
    // TEST
    sprite_quad[0][0].setTexture(*cross);
    sprite_quad[0][0].setColor(Color::Red);
    sprite_quad[0][2].setTexture(*nought);
    window.draw(sprite_quad[0][0]);
    window.draw(sprite_quad[0][2]);
}
