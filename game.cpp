#include "game.hpp"

using namespace sf;
using namespace std;

Game::Game(RenderWindow& windows) : window(windows), turn(CROSS)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            quad[i][j] = EMPTY;
        }
    }


    if (!crossI.loadFromFile("x.bmp") || !noughtI.loadFromFile("o.bmp"))
        cout << "FATAL ERROR" << endl;

    crossI.createMaskFromColor(Color::Black);
    noughtI.createMaskFromColor(Color::Red);

    cross = new Texture();
    nought = new Texture();

    cross->loadFromImage(crossI);
    nought->loadFromImage(noughtI);

    cross->setSmooth(true);
    nought->setSmooth(true);

    quad[2][1] = CROSS;
    quad[2][2] = NOUGHT;

    cout << won() << endl;
}

void Game::drawQuad() {

    RectangleShape quadd[5];
    for (int i = 0 ; i < 3 ; i ++) {
        quadd[i].setSize(Vector2f(610, 5));
    }
    for (int j = 3 ; j < 5 ; j++) {
        quadd[j].setSize(Vector2f(5, 615));
    }

    quadd[0].setPosition(0, 510);
    quadd[1].setPosition(0, 310);
    quadd[2].setPosition(0, 110);
    quadd[3].setPosition(200, 110);
    quadd[4].setPosition(405, 110);

    for (int i = 0 ; i <= 4 ; i++) {
        quadd[i].setFillColor(Color::Black);
        window.draw(quadd[i]);
    }

    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++) {
            sprite_quad[i][j].setPosition(i*205, 115+j*200);
            sprite_quad[i][j].setScale(1.3333f, 1.3333f);
        }
    }
}

void Game::drawPlay() {

    for (int i = 0 ; i<3;i++) {
        for (int j = 0 ; j<3 ; j++) {
            if (quad[i][j] == CROSS) {
                sprite_quad[i][j].setTexture(*cross);
            } else if (quad[i][j] == NOUGHT) {
                sprite_quad[i][j].setTexture(*nought);
            }
            window.draw(sprite_quad[i][j]);
        }
    }
}

bool Game::won()
{
    for (int i = 0 ; i <3 ; i++) {
        if (quad[i][0]!=EMPTY) {
            if ((quad[i][0] == quad[i][1]) && (quad[i][0] == quad[i][2]))
                                sprite_quad[i][0].setColor(Color::Red);
                sprite_quad[i][1].setColor(Color::Red);
                sprite_quad[i][2].setColor(Color::Red);
                return true;
        }
    }

    for (int i = 0 ; i < 3 ; i++) {
        if(quad[0][i] != EMPTY) {
             if ((quad[0][i] == quad[1][i]) && (quad[0][i] == quad[2][i]))
                sprite_quad[0][i].setColor(Color::Red);
                sprite_quad[1][i].setColor(Color::Red);
                sprite_quad[2][i].setColor(Color::Red);
                return true;
        }
    }

    if (quad[1][1]!=EMPTY) {
        if ((quad[0][0]!=EMPTY) && (quad[0][0] == quad[1][1]) && (quad[0][0] == quad[2][2]))
                sprite_quad[0][0].setColor(Color::Red);
                sprite_quad[1][1].setColor(Color::Red);
                sprite_quad[2][2].setColor(Color::Red);
                return true;
        if ((quad[2][0] != EMPTY) && (quad[2][0] == quad[1][1]) && (quad[1][1] == quad[0][2]))
                sprite_quad[0][2].setColor(Color::Red);
                sprite_quad[1][1].setColor(Color::Red);
                sprite_quad[2][0].setColor(Color::Red);
                return true;
    }

    return false;
}
