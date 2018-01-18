//
// Created by Falcon on 09.11.17.
//
#pragma once

namespace sf {
    class Texture;
    class Font;
}

namespace Textures {
    enum id {
        cursor = 0,
        panel,
        button,
        map,
        gold,
        wood,
        food,
        exit,
        soundOn,
        soundOff,
        musicOn,
        musicOff,
    };
}

namespace Fonts {
    enum id {
        font1 = 0,
        font2,
        font3,
    };
}

template<typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::id> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::id> FontHolder;