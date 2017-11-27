//
// Created by Falcon on 08.11.17.
//

#pragma once

#include <unordered_set>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class MapCell : public sf::Drawable, public  sf::Transformable
{
public:
    MapCell();
    ~MapCell();

    void setTexture(const sf::Texture &texture, sf::IntRect rect);
    void setTileNumber(int number);
    void setCellPosition(int x, int y);
    const int getTileNumber() const;

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    int tileNumber;
    sf::Vector2i position;
    sf::Sprite sprite;
};


