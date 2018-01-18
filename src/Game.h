//
// Created by Falcon on 09.11.17.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "StateManager.h"
#include "GameContext.h"
#include "Camera.h"
//#include "MenuState.h"
#include "PauseState.h"
#include "GameState.h"
#include "Map.h"

class Game {
public:
    Game();

    void run();

private:
    void processEvents();
    void update(sf::Time dt);
    void draw();

    void registerStates();

    TextureHolder textureHolder;
    FontHolder fontHolder;
    sf::Font font;
    sf::RenderWindow window;
    States::Context context;
    Camera camera;
    StateManager manager;
};


