//
// Created by Falcon on 08.11.17.
//

#pragma once

#include "MapCell.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Map
{
public:
    Map(sf::RenderWindow &window);
    ~Map() = default;

    void draw();
    void highlightCell(const sf::Event &event, const Camera camera);

private:
    void loadFromCSV(const std::string &filename);

    bool selected;
    sf::Texture texture;
    std::vector<std::vector<MapCell>> matrixMap;
    sf::RenderWindow &window;
    int selectedX;
    int selectedY;
};


