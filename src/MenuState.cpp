//
// Created by Arthur  on 12/14/17.
//

#include "MenuState.h"
#include "Game.h"

MenuState::MenuState(StateManager &stack, States::Context context): State(stack, context) {
    selectedItemIndex = 0;

    sf::RenderWindow &window = *getContext().window;
    float width = window.getSize().x;
    float height = window.getSize().y;
    font.loadFromFile("..//Resources/sansation.ttf");

    sf::View view;
    view.setSize(static_cast<float>(960), static_cast<float>(720)); //480
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    view.setViewport({ 0.f, 0.f, 1.f, 1.f });
    window.setView(view);

    menu[0].setFont(font);
    menu[0].setString("Back to Game");
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBERS_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Settings");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBERS_OF_ITEMS + 2) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBERS_OF_ITEMS + 3) * 3));
}

void MenuState::draw() {
    getContext().window->clear();

    //background
    sf::Texture texture;
    texture.loadFromFile("../Resources/back.png");
    sf::Sprite background(texture);
    background.scale(960 / 350, 720 / 200);
    getContext().window->draw(background);
    //end of background code

    for (int i = 0; i < MAX_NUMBERS_OF_ITEMS; i++) {
        getContext().window->draw(menu[i]);
    }
}

int MenuState::GetSelectedItem() {
    return selectedItemIndex;
}

bool MenuState::update(sf::Time dt) {
    return false;
}

bool MenuState::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            MoveUp();
        }
        if (event.key.code == sf::Keyboard::Down) {
            MoveDown();
        }
        if (event.key.code == sf::Keyboard::Return) {
            if (GetSelectedItem() == 0) {
                pushState(States::ID::Game);
            }
            if (GetSelectedItem() == 2) {
                exit(0);
            }
        }
    }

    return false;
}

void MenuState::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MenuState::MoveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBERS_OF_ITEMS) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}