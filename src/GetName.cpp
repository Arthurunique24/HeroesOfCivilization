//
// Created by Arthur  on 1/21/18.
//

#include "GetName.h"

GetName::GetName(StateManager &stack, States::Context context) : State(stack, context) {
    sf::RenderWindow &window = *getContext().window;
    float width = window.getSize().x;
    float height = window.getSize().y;
    font.loadFromFile("../Resources/sansation.ttf");

    sf::View view;
    view.setSize(static_cast<float>(960), static_cast<float>(720)); //480
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    view.setViewport({ 0.f, 0.f, 1.f, 1.f });
    window.setView(view);

    textView.setFont(font);
    textView.setString("Enter name");
    textView.setFillColor(sf::Color::Red);
    textView.setPosition(sf::Vector2f(width / 2, height / 5));
}

void GetName::draw() {
    getContext().window->clear();
    getContext().window->draw(textView);
}

bool GetName::update(sf::Time dt) {
    return false;
}

bool GetName::handleEvent(const sf::Event &event) {
    if (event.key.code == sf::Keyboard::Q) {
        text.append("q");
    }
    if (event.key.code == sf::Keyboard::W) {
        text.append("w");
    }
    if (event.key.code == sf::Keyboard::E) {
        text.append("e");
    }
    if (event.key.code == sf::Keyboard::R) {
        text.append("r");
    }
    if (event.key.code == sf::Keyboard::T) {
        text.append("t");
    }
    if (event.key.code == sf::Keyboard::Y) {
        text.append("y");
    }
    if (event.key.code == sf::Keyboard::U) {
        text.append("u");
    }
    if (event.key.code == sf::Keyboard::I) {
        text.append("i");
    }
    if (event.key.code == sf::Keyboard::O) {
        text.append("o");
    }
    if (event.key.code == sf::Keyboard::A) {
        text.append("a");
    }
    if (event.key.code == sf::Keyboard::S) {
        text.append("s");
    }
    if (event.key.code == sf::Keyboard::Q) {
        text.append("q");
    }
    if (event.key.code == sf::Keyboard::D) {
        text.append("d");
    }
    if (event.key.code == sf::Keyboard::F) {
        text.append("f");
    }
    if (event.key.code == sf::Keyboard::G) {
        text.append("g");
    }
    if (event.key.code == sf::Keyboard::H) {
        text.append("h");
    }
    if (event.key.code == sf::Keyboard::J) {
        text.append("j");
    }
    if (event.key.code == sf::Keyboard::K) {
        text.append("k");
    }
    if (event.key.code == sf::Keyboard::L) {
        text.append("l");
    }
    if (event.key.code == sf::Keyboard::Z) {
        text.append("z");
    }
    if (event.key.code == sf::Keyboard::X) {
        text.append("x");
    }
    if (event.key.code == sf::Keyboard::C) {
        text.append("c");
    }
    if (event.key.code == sf::Keyboard::V) {
        text.append("v");
    }
    if (event.key.code == sf::Keyboard::B) {
        text.append("b");
    }
    if (event.key.code == sf::Keyboard::N) {
        text.append("n");
    }
    if (event.key.code == sf::Keyboard::M) {
        text.append("m");
    }
    if (event.key.code == sf::Keyboard::Num0) {
        text.append("0");
    }
    if (event.key.code == sf::Keyboard::Num1) {
        text.append("1");
    }
    if (event.key.code == sf::Keyboard::Num2) {
        text.append("2");
    }
    if (event.key.code == sf::Keyboard::Num3) {
        text.append("3");
    }
    if (event.key.code == sf::Keyboard::Num4) {
        text.append("4");
    }
    if (event.key.code == sf::Keyboard::Num5) {
        text.append("5");
    }
    if (event.key.code == sf::Keyboard::Num6) {
        text.append("6");
    }
    if (event.key.code == sf::Keyboard::Num7) {
        text.append("7");
    }
    if (event.key.code == sf::Keyboard::Num8) {
        text.append("8");
    }
    if (event.key.code == sf::Keyboard::Num9) {
        text.append("9");
    }
    if (event.key.code == sf::Keyboard::Return) {
        std::cout << text << std::endl;
        pushState(States::ID::Game);
        return true;
    }
    return false;
}
