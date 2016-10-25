#include "game.hpp"

using namespace sf;
using namespace std;

Game::Game(RenderWindow& windows) : window(windows), turn(CROSS)
{
    for (int i = 0 ; i < 3 ; i++) //Initialization of the "virtual" map of the game.
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
    nought->setSmooth(true); // Ready to be used !

    quad[1][1] = CROSS; // TEST !
    quad[2][2] = CROSS;
    quad[0][0] = CROSS;
    quad[1][2] = NOUGHT;
    quad[0][2] = NOUGHT;

    cout << won() << endl;
}

void Game::drawQuad() { // Draw the grid

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
            sprite_quad[i][j].setScale(1.3333f, 1.3333f); // One case is 200px large  and the pictures are 150px large....
        }
    }
}

void Game::drawPlay() { // Draw the grid from the virtual map by using the textures

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
void Game::drawText() {
    if (!font.loadFromFile("comic.ttf"))
        cout << "FATAL_ERROR" << endl;

    Text title;
    title.setFont(font);
    title.setCharacterSize(40);
    title.setColor(Color::Red);
    title.setStyle(Text::Bold);
    title.setString("Morpion");
    title.setPosition(305-title.getGlobalBounds().width/2, 10);

    Text turn_ply;
    turn_ply.setFont(font);
    turn_ply.setCharacterSize(24);
    turn_ply.setColor(Color::Red);

    if (turn == CROSS)
        turn_ply.setString("Au tour de Joueur 1");
    else
        turn_ply.setString("Au tour de Joueur 2");

    turn_ply.setPosition(2, 75);

    Text score;
    score.setFont(font);
    score.setColor(Color::Blue);
    score.setCharacterSize(20);
    score.setString("SCORE\nJoueur 1 : 00 \nJoueur 2 : 00");
    score.setPosition(610-score.getGlobalBounds().width-10, 1);

    window.draw(title);
    window.draw(turn_ply);
    window.draw(score);
}

bool Game::won() // Return true if someone has won
{
    // Check the columns
    for (int i = 0 ; i <3 ; i++) {
        if (quad[i][0]!=EMPTY) {
            if (quad[i][0] == quad[i][1] && quad[i][0] == quad[i][2]) {
                sprite_quad[i][0].setColor(Color::Red);
                sprite_quad[i][1].setColor(Color::Red);
                sprite_quad[i][2].setColor(Color::Red);
                cout << "THIS ONE";
                return true;
            }
        }
    }

    // Check the lines
    for (int i = 0 ; i < 3 ; i++) {
        if(quad[0][i] != EMPTY) {
                cout << "THIS ONE33";
             if (quad[0][i] == quad[1][i] && quad[2][i] == quad[0][i]) {
                 cout << "TEST" << endl;
                sprite_quad[0][i].setColor(Color::Red);
                sprite_quad[1][i].setColor(Color::Red);
                sprite_quad[2][i].setColor(Color::Red);
                return true;
             }
        }
    }

    // Check the diagonals
    if (quad[1][1]!=EMPTY) {
        if ((quad[0][0]!=EMPTY) && (quad[0][0] == quad[1][1] && quad[1][1] == quad[2][2])) {
                sprite_quad[0][0].setColor(Color::Red);
                sprite_quad[1][1].setColor(Color::Red);
                sprite_quad[2][2].setColor(Color::Red);
                return true;
        } if ((quad[2][0] != EMPTY) && (quad[2][0] == quad[1][1] && quad[1][1] == quad[0][2])) {
                sprite_quad[0][2].setColor(Color::Red);
                sprite_quad[1][1].setColor(Color::Red);
                sprite_quad[2][0].setColor(Color::Red);
                return true;
        }
    }
    return false;
}
