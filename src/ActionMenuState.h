//
// Created by Arthur  on 1/20/18.
//

#ifndef HEROESOFCIVILIZATION_ACTIONMENU_H
#define HEROESOFCIVILIZATION_ACTIONMENU_H

#include <SFML/Graphics.hpp>
#include "GameContext.h"
#include "State.h"
#include "Camera.h"

#define MAX_NUMBER_OF_BUILDINGS 4

class ActionMenuState: public State {
public:
    explicit ActionMenuState(StateManager &stack, States::Context context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;
    void MoveUp();
    void MoveDown();
    int GetSelectedItem();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_BUILDINGS];
};


#endif //HEROESOFCIVILIZATION_ACTIONMENU_H
