//
// Created by Arthur  on 1/20/18.
//

#include "ActionMenuState.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include "Camera.h"


ActionMenuState::ActionMenuState(StateManager &stack, States::Context context): State(stack, context) {
    selectedItemIndex = 0;

    sf::RenderWindow &window = *getContext().window;
    float width = window.getSize().x;
    float height = window.getSize().y;
    font.loadFromFile("../Resources/sansation.ttf");

    sf::View view;
    view.setSize(static_cast<float>(960), static_cast<float>(720)); //480
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    view.setViewport({ 0.f, 0.f, 1.f, 1.f });
    window.setView(view);

    menu[0].setFont(font);
    menu[0].setString("Farm");
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_BUILDINGS + 3) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Sawmill");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_BUILDINGS + 4) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Mine");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_BUILDINGS + 4) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Barracks");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_BUILDINGS + 4) * 4));
}

void ActionMenuState::draw() {
    getContext().window->clear();

    for (int i = 0; i < MAX_NUMBER_OF_BUILDINGS; i++) {
        getContext().window->draw(menu[i]);
    }
}

bool ActionMenuState::update(sf::Time dt) {
    return false;
}

bool ActionMenuState::handleEvent(const sf::Event &event) {
    std::ifstream coords("../Resources/coordinates");
    assert(coords);
    int X;
    int Y;

    coords >> X >> Y;

    coords.close();

    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            MoveUp();
        }
        if (event.key.code == sf::Keyboard::Down) {
            MoveDown();
        }
        if (event.key.code == sf::Keyboard::Escape) {
            pushState(States::ID::Game);
        }
        if (event.key.code == sf::Keyboard::Return) {
            //Farm
            if (GetSelectedItem() == 0) {
                Remap(X, Y, 5);
                pushState(States::ID::Game);
            }
            //Sawmill
            if (GetSelectedItem() == 1) {
                Remap(X, Y, 74);
                pushState(States::ID::Game);
            }
            //Mine
            if (GetSelectedItem() == 2) {
                Remap(X, Y, 54);
                pushState(States::ID::Game);
            }
            //Barracks
            if (GetSelectedItem() == 3) {
                Remap(X, Y, 20);
                pushState(States::ID::Game);
            }
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        pushState(States::ID::Game);
    }

    return false;
}

void ActionMenuState::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void ActionMenuState::MoveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_BUILDINGS) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int ActionMenuState::GetSelectedItem() {
    return selectedItemIndex;
}

void ActionMenuState::Remap(int x, int y, int type) {
    std::string fileName;
    fileName = "../Resources/map.csv";
    std::ifstream fin(fileName);

    int map[12][15];
    int tileNumber;
    char coma;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 15; j++) {
            fin >> tileNumber;
            map[i][j] = tileNumber;
            fin >> coma;
        }
    }
//    farm: 4, 11, 12, 19, 51, 67, 82, 95;
//    Sawmill: 53, 60, 83, 89, 94;
//    Mine: 39, 40, 43, 46, 50, 57, 72, 75, 80;
//    Barracks: 6, 13, 22, 23, 31, 31, 33, 45, 47, 57, 66, 67, 68;

    if (type == 5) {
        if (map[x][y] != 4 && map[x][y] != 11 && map[x][y] != 12
            && map[x][y] != 19 && map[x][y] != 51 && map[x][y] != 67
            && map[x][y] != 82 && map[x][y] != 95)
        {
            return;
        }
    } else if (type == 74) {
        if (map[x][y] != 53 && map[x][y] != 60 && map[x][y] != 83
            && map[x][y] != 89 && map[x][y] != 94)
        {
            return;
        }
    } else if (type == 54) {
        if (map[x][y] != 39 && map[x][y] != 40 && map[x][y] != 43
            && map[x][y] != 46 && map[x][y] != 50 && map[x][y] != 57
            && map[x][y] != 72 && map[x][y] != 75 && map[x][y] != 80)
        {
            return;
        }
    } else if (type == 3) {
        if (map[x][y] != 6 && map[x][y] != 13 && map[x][y] != 22
            && map[x][y] != 31 && map[x][y] != 33 && map[x][y] != 45
            && map[x][y] != 47 && map[x][y] != 66 && map[x][y] != 67
            && map[x][y] != 57 && map[x][y] != 23)
        {
            return;
        }
    }


    map[x][y] = type;

    fin.clear();
    fin.seekg(0);
    fin.close();

    std::ofstream fin1(fileName);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 15; j++) {
            fin1 << map[i][j] << ",";
        }
        fin1 << std::endl;
    }

    fin1.close();
}
