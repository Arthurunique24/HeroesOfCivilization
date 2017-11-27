//
// Created by Falcon on 09.11.17.
//

#ifndef HEROESOFCIVILIZATION_GAME_H
#define HEROESOFCIVILIZATION_GAME_H


#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "GameContext.h"
#include "Camera.h"
#include "Map.h"

class Game {
public:
    Game();

    void run();

private:
    void processEvents();
    void update(sf::Time dt);
    void draw();

    sf::RenderWindow window;
    TextureHolder textureHolder;
    States::Context context;
    Camera camera;
    Map map;
};


#endif //HEROESOFCIVILIZATION_GAME_H
