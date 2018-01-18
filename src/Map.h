//
// Created by Falcon on 08.11.17.
//

#pragma once

#include "MapCell.h"
#include <vector>


class Map
{
public:
    Map(sf::RenderWindow &window);
    ~Map() = default;

    void draw();

private:
    void loadFromCSV(const std::string &filename);

    sf::Texture texture;
    std::vector<std::vector<MapCell>> matrixMap;
    sf::RenderWindow &window;
};


