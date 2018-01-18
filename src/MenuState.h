//
// Created by Falcon on 21.12.17.
//

#pragma once

#include <iostream>
#include "State.h"
#include <SFML/Graphics.hpp>

#define MAX_NUMBERS_OF_ITEMS 3

class MenuState: public State {
public:
    MenuState(StateManager &stack, States::Context context);
    ~MenuState();

    void StartMenu(sf::RenderWindow &);
    void Draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetSelectedItem();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBERS_OF_ITEMS];
};
