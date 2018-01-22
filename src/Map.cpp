//
// Created by Falcon on 08.11.17.
//
#include <fstream>
#include <iostream>
#include <cassert>
#include "Map.h"
#include "Constants.h"

Map::Map(sf::RenderWindow &window) : window(window)
{
    texture.loadFromFile("../Resources/mapTexture.png"); //если текущая директория папка src. Если не работает, то можно указать полный путь
    texture.setSmooth(true);

    matrixMap.resize(MAP_HEIGHT, std::vector<MapCell>(MAP_WIDTH));
    loadFromCSV("../Resources/map.csv");
    selected = false;

}

void Map::draw()
{
    window.clear();
    for (int i = 0; i < MAP_HEIGHT; i++)
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            window.draw(matrixMap[i][j]);
            if (matrixMap[i][j].isSelect())
            {
                sf::Sprite sprite;
                sf::IntRect rect{(TILE_WIDTH + 2) * 1, (TILE_HEIGHT + 2) * 4, TILE_WIDTH, TILE_HEIGHT};
                sprite.setTexture(texture);
                sprite.setTextureRect(rect);
                sprite.setPosition(static_cast<float>(j * TILE_WIDTH + (TILE_WIDTH / 2) * (i % 2)), static_cast<float>(i * 0.75 * TILE_HEIGHT));
                window.draw(sprite);
            }
        }
}


void Map::highlightCell(const sf::Event &event, Camera camera)
{
    int y = int(static_cast<float>(event.mouseButton.y) + camera.getView().getCenter().y - 360) / 107;
    int x = (static_cast<float>(event.mouseButton.x) + camera.getView().getCenter().x - 480 - 60 * (y % 2)) / 120;
    std::cout << "X: " << x << " Y: " << y << std::endl;

    std::ofstream coord("../Resources/coordinates");
    assert(coord);

    coord << y << " " << x;

    coord.clear();
    coord.close();

    if (!selected) {
        matrixMap[y][x].select();
        selectedX = x;
        selectedY = y;
        selected = true;
    } else
    {
        matrixMap[selectedY][selectedX].select();
        if (x == selectedX && y == selectedY)
            selected = false;
        else
        {
            matrixMap[y][x].select();
            selectedX = x;
            selectedY = y;
        }
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
            sf::IntRect rect{ (TILE_WIDTH + 2) * (tileNumber % 7) + 1 , (TILE_HEIGHT + 2) * (tileNumber / 7), TILE_WIDTH, TILE_HEIGHT };
            matrixMap[i][j].setTexture(texture, rect);
            //matrixMap[i][j].setPosition(static_cast<float>(0), static_cast<float>(0));
            matrixMap[i][j].setCellPosition(j, i);

            fin >> comma;
        }
    }
    fin.close();
}
