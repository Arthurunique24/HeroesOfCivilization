//
// Created by Falcon on 09.11.17.
//

#ifndef HEROESOFCIVILIZATION_GAMECONTEXT_H
#define HEROESOFCIVILIZATION_GAMECONTEXT_H

#include "ResourceManager/ResourceIdentifier.h"
#include "ResourceManager/ResourceHolder.h"


namespace sf
{
    class RenderWindow;
    class Font;
    class Sprite;
}

class SoundManager;

namespace World
{
    struct GameData
    {
        int gold;
        int wood;
        int food;
    };
}

namespace States
{
    struct Context
    {
        explicit Context(sf::RenderWindow &window
                , TextureHolder &textureHolder) :
                window(&window)
                ,textureHolder(&textureHolder) {};
        sf::RenderWindow *window;
        TextureHolder *textureHolder;
    };
}

#endif //HEROESOFCIVILIZATION_GAMECONTEXT_H
