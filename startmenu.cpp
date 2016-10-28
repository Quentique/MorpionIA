#include "startmenu.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

StartMenu::StartMenu(RenderWindow& gwindow) : quit(false) {
if (!font.loadFromFile("comic.ttf"))
    cout << "ERROR DURING LOADING FONT";
}


