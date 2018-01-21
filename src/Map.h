//
// Created by Falcon on 08.11.17.
//

#pragma once

#include "MapCell.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Map
{
public:
    Map(sf::RenderWindow &window);
    ~Map() = default;

    void draw();
    void highlightCell(const sf::Event &event);

private:
    void loadFromCSV(const std::string &filename);

    sf::Texture texture;
    std::vector<std::vector<MapCell>> matrixMap;
    sf::RenderWindow &window;
};


