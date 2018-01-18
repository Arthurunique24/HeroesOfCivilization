//
// Created by Arthur  on 12/14/17.
//

#ifndef HEROESOFCIVILIZATION_MENU_H
#define HEROESOFCIVILIZATION_MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameContext.h"
#include "StateManager.h"
#include "State.h"

#define MAX_NUMBERS_OF_ITEMS 3

class MenuState: public State {
public:
    explicit MenuState(StateManager &stack, States::Context context);
    ~MenuState();

    void Draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetSelectedItem();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBERS_OF_ITEMS];
};


#endif //HEROESOFCIVILIZATION_MENU_H
