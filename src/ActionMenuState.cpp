//
// Created by Arthur  on 1/20/18.
//

#include "ActionMenuState.h"
#include "Game.h"

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
                //do somth
            }
            //Sawmill
            if (GetSelectedItem() == 1) {
                //do somth
            }
            //Mine
            if (GetSelectedItem() == 2) {
                //do somth
            }
            //Barracks
            if (GetSelectedItem() == 3) {
                //do somth
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
