//
// Created by Falcon on 08.11.17.
//

#include "MapCell.h"

MapCell::MapCell()
{}

MapCell::~MapCell()
{}

void MapCell::setTexture(const sf::Texture &texture, sf::IntRect rect)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
}

void MapCell::setTileNumber(int number)
{
    tileNumber = number;
}

void MapCell::setCellPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    this->setPosition(static_cast<float>(x * TILE_WIDTH + (TILE_WIDTH / 2) * (y % 2)), static_cast<float>(y * 0.75 * TILE_HEIGHT));
}

const int MapCell::getTileNumber() const
{
    return tileNumber;
}

void MapCell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}