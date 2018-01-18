//
// Created by Arthur  on 12/14/17.
//

#include "MenuState.h"

<<<<<<< HEAD
MenuState::MenuState() {
//    float width, float height
//
//
//    if (font.loadFromFile("../arial.ttf")) {
//
//    }
//    menu[0].setFont(font);
//    menu[0].setString("Back to Game");
//    menu[0].setFillColor(sf::Color::Red);
//    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBERS_OF_ITEMS + 1) * 1));
//
//    menu[1].setFont(font);
//    menu[1].setFillColor(sf::Color::White);
//    menu[1].setString("Settings");
//    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBERS_OF_ITEMS + 2) * 2));
//
//    menu[2].setFont(font);
//    menu[2].setFillColor(sf::Color::White);
//    menu[2].setString("Exit");
//    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBERS_OF_ITEMS + 3) * 3));
}

MenuState::~MenuState(StateManager &stack, States::Context context)) {

}

void MenuState::Draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBERS_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
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

int MenuState::GetSelectedItem() {
    return selectedItemIndex;
}

void MenuState::StartMenu(sf::RenderWindow &window) {
    float width = window.getSize().x;
    float height = window.getSize().y;
    if (font.loadFromFile("/Resources/sansation.ttf")) {
=======
MenuState::MenuState(StateManager &stack, States::Context context): State(stack, context) {
    sf::RenderWindow &window = *getContext().window;
    float width = window.getSize().x;
    float height = window.getSize().y;
    if (font.loadFromFile("../arial.ttf")) {
>>>>>>> master

    }
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

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    if (GetSelectedItem() == 2) {
                        exit(0);
                    }
                }
            }
        }

        window.clear();
        Draw(window);
        window.display();
    }
}

MenuState::~MenuState() {

}

void MenuState::Draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBERS_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
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

int MenuState::GetSelectedItem() {
    return selectedItemIndex;
}
