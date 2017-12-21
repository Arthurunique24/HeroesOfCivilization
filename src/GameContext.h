//
// Created by Falcon on 09.11.17.
//

#pragma once

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
                , sf::Font &font
                , TextureHolder &textureHolder
                , FontHolder &fontHolder) :
                window(&window)
                ,textureHolder(&textureHolder) {};
        sf::RenderWindow *window;
        sf::Font *font;
        TextureHolder *textureHolder;
        FontHolder *fontHolder;
    };
}

