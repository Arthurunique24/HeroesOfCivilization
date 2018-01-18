#pragma once

#include "State.h"
#include "Camera.h"

class PauseState : public State
{
public:
    explicit PauseState(StateManager &stack, States::Context context);

    bool handleEvent(const sf::Event &event) override ;
    bool update(sf::Time dt) override;
    void draw() override;

private:
    sf::Text pausedText, enterText, escText;
    sf::RectangleShape background;
    Camera camera;
};
