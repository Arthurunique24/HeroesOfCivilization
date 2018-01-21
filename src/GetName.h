//
// Created by Arthur  on 1/21/18.
//

#ifndef HEROESOFCIVILIZATION_GETNAME_H
#define HEROESOFCIVILIZATION_GETNAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameContext.h"
#include "State.h"
#include "Camera.h"

class GetName: public State {
public:
    explicit GetName(StateManager &stack, States::Context context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;

private:
    sf::Font font;
    std::string text;
    sf::Text textView;
};


#endif //HEROESOFCIVILIZATION_GETNAME_H
