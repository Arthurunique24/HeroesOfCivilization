#pragma once

#include <SFML/Graphics.hpp>

#include "GameContext.h"

class Camera
{
public:
    explicit Camera(States::Context context);

    void handleEvent(const sf::Event &event);
    void update(sf::Time dt);
    void setView(const sf::View newView);
    void draw();

    const sf::View &getView();
private:

    sf::View view;
    States::Context context;
    sf::Vector2u windowSize;
    sf::Vector2i initialMousePos;
    bool dragging;
};

