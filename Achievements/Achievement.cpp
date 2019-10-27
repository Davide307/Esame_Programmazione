//
// Created by davide on 26/10/19.
//

#include "Achievement.h"
#include "SFML/Graphics.hpp"
#include "iostream"

Achievement::Achievement() {
    boxPos.x = 20;
    boxPos.y = 20;
    font.loadFromFile("../textures/arial_narrow_7.ttf");
    textPopUp.setPosition(boxPos);
    textPopUp.setFillColor(sf::Color(255, 255, 255, 0));
    textPopUp.setFont(font);
    textPopUp.setCharacterSize(characterSize);
    description.setFont(font);
    description.setCharacterSize(sizeText);
    unlocked.setCharacterSize(sizeText);
    unlocked.setFillColor(sf::Color::Red);
    unlocked.setString("Not Achieved");
    unlocked.setFont(font);
}

void Achievement::update() {
    achieved = true;
    unlocked.setFillColor(sf::Color::Green);
    unlocked.setString("Achieved");
}

void Achievement::drawPopUp(sf::RenderWindow *window) {
    if (achieved) {
        firstFrame = clock->getElapsedTime();
    }
    if (achieved && firstFrame + popUpLife >= clock->getElapsedTime() && !nodraw && !endDraw) {
        textPopUp.setFillColor(sf::Color(255, 255, 255, i));
        window->draw(textPopUp);
        if (i <= 255) {
            i = i + opacity;
        }
        if (i == 255) {
            nodraw = true;
        }
    }
    if (achieved && (firstFrame + popUpLife + popUpLife) >= clock->getElapsedTime() && nodraw && !endDraw) {
        textPopUp.setFillColor(sf::Color(255, 255, 255, i));
        window->draw(textPopUp);
        if (i >= 0) {
            i = i - opacity;
        }
        if (i == 0) {
            endDraw = true;
        }

    }
}
