//
// Created by davide on 16/09/19.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H
#define SIZE 2

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "GameStates.h"

class Menu {

public:
    Menu();

    void update(Input input, GameStates *state, sf::RenderWindow *window);
    void drawMenu(sf::RenderWindow *window);

private:
    sf::Text menu[SIZE];
    sf::Font Font;
    int selected = 0;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    unsigned int textSize = 30;
};


#endif //GAME_MENU_H
