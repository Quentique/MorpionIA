#include "game.hpp"
#include <string>
#include <sstream>

using namespace sf;
using namespace std;

Game::Game(RenderWindow& windows) : window(windows), turn(CROSS), player1(CROSS), player2(NOUGHT)
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
    empty_text = new Texture();
    empty_text->create(150, 150);

    cross->loadFromImage(crossI);
    nought->loadFromImage(noughtI);

    cross->setSmooth(true);
    nought->setSmooth(true); // Ready to be used !
    player2++;
    player2--;
    cout << player2.getWonStroke() << " e " << player2.getLostStroke() << endl;
    end_play = false;
    null = false;

    quad[0][2] = NOUGHT;
    draw(1, 1, NOUGHT);
    cancel(0, 2);
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
string Game::IntToString(int number)
{
    ostringstream oss;
    oss << number;
    return oss.str();
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

    if (end_play)
    {
        if (null)
        {
            turn_ply.setString("Partie nulle");
        } else {
        string name_winner = (turn==NOUGHT)?player1.getName():player2.getName();
        turn_ply.setString("Le gagnant est : " + name_winner);
        }

    } else {
    if (turn == CROSS)
        turn_ply.setString("Au tour de " + player1.getName());
    else {turn_ply.setString("Au tour de " + player2.getName()); }
    }
    turn_ply.setPosition(2, 75);


    Text score;
    score.setFont(font);
    score.setColor(Color::Blue);
    score.setCharacterSize(20);
    score.setString("SCORE\n"+ player1.getName() +" : " + IntToString(player1.getScore()) +"\n"+ player2.getName()+" : " + Game::IntToString(player2.getScore()));
    score.setPosition(610-score.getGlobalBounds().width-10, 1);

    window.draw(title);
    window.draw(turn_ply);
    window.draw(score);
}
void Game::drawRestart() {
Text ask;
ask.setFont(font);
ask.setCharacterSize(30);
ask.setColor(Color::Green);
ask.setString("Voulez-vous recommencer une partie ?\n                       (O/N)");

ask.setPosition(305-ask.getGlobalBounds().width/2, 357);
window.draw(ask);
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
             if (quad[0][i] == quad[1][i] && quad[2][i] == quad[0][i]) {
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
void Game::draw(int gx, int gy, Case gstate) {

    if (quad[gx][gy] == EMPTY)
    {
        quad[gx][gy] = gstate;
    }
}
void Game::cancel(int gx, int gy) {
    quad[gx][gy] = EMPTY;
}

array<int, 2> Game::getCase(int mouse_x, int mouse_y) {
    int y = -1;
    int x = -1;

    if (mouse_x > 0 && mouse_x < 200) {  x = 0; }
    else if (mouse_x > 200 && mouse_x < 405) { x = 1; }
    else if (mouse_x > 405 && mouse_x < 610) { x = 2; }

    if (mouse_y > 110 && mouse_y < 310) { y = 0; }
    else if (mouse_y > 310 && mouse_y < 510) { y = 1; }
    else if (mouse_y > 510 && mouse_y < 715) { y = 2; }

    return {x, y};
}
void Game::play(int mouse_x, int mouse_y) {
    array<int, 2> coor = getCase(mouse_x, mouse_y);

    if (coor.at(1) != -1) {
        draw(coor.at(0), coor.at(1), turn);
        if (won())
        {
            end_play = true;
            if (turn == CROSS) {
                player1.make_win();
                player2.make_lose();
            } else {
                player2.make_win();
                player1.make_lose();
            }
        }
        int nb_empty;
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                if (quad[i][j] == EMPTY)
                    nb_empty++;
            }
        }
        if (nb_empty == 0 && !end_play) {
            end_play = true;
            null = true;
        }
        turn = (turn==CROSS)?NOUGHT:CROSS;
    }
}
void Game::reset() {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            quad[i][j] = EMPTY;
            sprite_quad[i][j] = Sprite();
        }
    }
    end_play = false;
    null = false;
    turn = (turn==CROSS)?NOUGHT:CROSS;
}
bool Game::play_finished() { return end_play; }
