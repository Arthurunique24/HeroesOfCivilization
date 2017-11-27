//
// Created by Falcon on 09.11.17.
//

#include "Game.h"
#include "Map.h"
#include <SFML/System/Time.hpp>
#include "ResourceManager/ResourceIdentifier.h"
#include "ResourceManager/ResourceHolder.h"

Game::Game() : window({960, 720}, "Heroes Of Civilization", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings{0, 0, 8, 1, 1, 0, false}),
               context(window, textureHolder), map(*context.window),
               camera(context)
{}

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

            processEvents();
        }
    }
}

void Game::processEvents()
{
    sf::Event event;
    camera.handleEvent(event);
    draw();
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time dt)
{
    sf::Time timePerFrame = sf::seconds(1.f / 30.f);
    camera.update(dt);
}

void Game::draw()
{
    window.setView(camera.getView());
    window.clear(sf::Color(210, 210, 210));
    map.draw();
    window.display();
}