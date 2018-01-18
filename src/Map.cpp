//
// Created by Falcon on 08.11.17.
//
#include <fstream>
#include <iostream>
#include "Map.h"
#include "Constants.h"

Map::Map(sf::RenderWindow &window) : window(window)
{
    texture.loadFromFile("../Resources/mapTexture.png"); //если текущая директория папка src. Если не работает, то можно указать полный путь
    texture.setSmooth(true);

    matrixMap.resize(MAP_HEIGHT, std::vector<MapCell>(MAP_WIDTH));
    loadFromCSV("../Resources/map.csv");
}

void Map::draw()
{
    for (int i = 0; i < MAP_HEIGHT; i++)
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            window.draw(matrixMap[i][j]);
        }
}

void Map::loadFromCSV(const std::string &filename)
{
    std::ifstream fin(filename);

    char comma;
    int tileNumber;

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            fin >> tileNumber;

            matrixMap[i][j].setTileNumber(tileNumber);
            sf::IntRect rect{ (TILE_WIDTH + 2) * 5 , (TILE_HEIGHT + 2) * 0, TILE_WIDTH, TILE_HEIGHT };
            matrixMap[i][j].setTexture(texture, rect);
            //matrixMap[i][j].setPosition(static_cast<float>(0), static_cast<float>(0));
            matrixMap[i][j].setCellPosition(j, i);

            fin >> comma;
        }
    }
    fin.close();
}