//
// Created by Arthur  on 12/14/17.
//

#ifndef HEROESOFCIVILIZATION_MENUSTATE_H
#define HEROESOFCIVILIZATION_MENUSTATE_H

#include <SFML/Graphics.hpp>
#include "GameContext.h"
#include "State.h"
#include "Camera.h"

#define MAX_NUMBERS_OF_ITEMS 3

class MenuState: public State {
public:
    explicit MenuState(StateManager &stack, States::Context context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;
    void MoveUp();
    void MoveDown();
    int GetSelectedItem();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBERS_OF_ITEMS];
};

#endif //HEROESOFCIVILIZATION_ACTIONMENU_H
