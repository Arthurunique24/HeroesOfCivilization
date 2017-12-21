//
// Created by Falcon on 21.12.17.
//

#pragma once

#include "State.h"
#include "ResourceManager/ResourceHolder.h"
#include "ResourceManager/ResourceIdentifier.h"
#include "Map.h"
#include "Camera.h"
#include "SFML/System/Time.hpp"

class GameState : public State {
public:
    explicit GameState(StateManager &stack, States::Context context);
    ~GameState() = default;

    bool handleEvent(const sf::Event &event) override;
    bool update(sf::Time dt) override ;
    void draw() override;

private:
    sf::RenderWindow window;
    TextureHolder textureHolder;
//    States::Context context;
    Camera camera;
    Map map;
};

