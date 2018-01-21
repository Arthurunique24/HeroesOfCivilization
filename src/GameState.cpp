//
// Created by Falcon on 21.12.17.
//

#include "GameState.h"
#include "Game.h"

GameState::GameState(StateManager &stack, States::Context context)
        : State(stack, context)
        , camera(context)
        , map(*context.window)

{}

bool GameState::handleEvent(const sf::Event &event)
{
    camera.handleEvent(event);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        pushState(States::ID::Menu);
    } else
        if (event.type == sf::Event::MouseButtonReleased)
            map.highlightCell(event, camera);

}

bool GameState::update(sf::Time dt)
{
    camera.update(dt);
}

void GameState::draw()
{
    window.setView(camera.getView());
    map.draw();
}