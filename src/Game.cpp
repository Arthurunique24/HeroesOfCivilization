//
// Created by Falcon on 09.11.17.
//

#include "Game.h"
#include "Map.h"
#include <SFML/System/Time.hpp>
#include "ResourceManager/ResourceIdentifier.h"
#include "ResourceManager/ResourceHolder.h"

Game::Game() : window({960, 720}, "Heroes Of Civilization", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings{0, 0, 8, 1, 1, 0, false}),
               context(window, font, textureHolder, fontHolder),
               manager(context),
               camera(context)
{
    fontHolder.load(Fonts::font1, "/../Resources/sansation.ttf");

    registerStates();
    manager.pushState(States::ID::Menu);
}

void Game::run()
{
    const sf::Time frameTime = sf::seconds(1.f / 30.f);
    sf::Clock clock;
    sf::Time passedTime = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();

        passedTime += elapsedTime;

        while (passedTime > frameTime)
        {
            passedTime -= frameTime;

            processEvents();
            update(frameTime);

            if (manager.isEmpty())
                window.close();
        }

        draw();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        manager.processEvents(event);
    }
}

void Game::update(sf::Time frameTime)
{
    manager.update(frameTime);
}

void Game::draw()
{
    window.clear(sf::Color(210, 210, 210));
    manager.draw();
    window.display();
}

void Game::registerStates()
{
    manager.registerState<GameState>(States::ID::Game);
    manager.registerState<MenuState>(States::ID::Menu);
    manager.registerState<PauseState>(States::ID::Pause);
}