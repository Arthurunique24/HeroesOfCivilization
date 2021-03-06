#include "Camera.h"
#include "Constants.h"
#include <iostream>
#include <cmath>

Camera::Camera(States::Context context)
        : context(context)
        , dragging(false)
{
    windowSize = context.window->getSize();
    view.setSize(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)); //480
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    view.setViewport({ 0.f, 0.f, 1.f, 1.f });

    context.window->setView(view);
}

void Camera::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed
        && event.key.code == sf::Mouse::Right) {
        initialMousePos = sf::Mouse::getPosition(*context.window);
        dragging = true;
    } else if (event.type == sf::Event::MouseButtonReleased
               && event.key.code == sf::Mouse::Right) {
        dragging = false;
    }
}

void Camera::setView(sf::View newView)
{
    view = newView;
}
//    else if (event.type == sf::Event::MouseWheelMoved)
//    {
//    	int factor = 1 + event.mouseWheel.delta;// *-0.1f;
//    	std::cout << "mousewheel: " << event.mouseWheel.delta << std::endl;
//    	std::cout << factor << std::endl;
//    	std::cout << view.getSize().x << ' ' << view.getSize().y << std::endl;
//    	view.zoom(factor);
//    	if (view.getSize().x > 1280) view.setSize({ 1280, view.getSize().y });
//    	if (view.getSize().y > 960) view.setSize({ view.getSize().x, 960 });
//
//    	if (view.getSize().x < 160) view.setSize({ 160, view.getSize().y });
//    	if (view.getSize().y < 120) view.setSize({ view.getSize().x, 120 });
//
//    	view.setSize(std::floor(view.getSize().x), std::floor(view.getSize().y));
//    	view.setCenter({ std::floor(view.getCenter().x), std::floor(view.getCenter().y) });
//
//    	context.window->setView(view);
//    }
//}

void Camera::update(sf::Time dt)
{
//    if (dragging)
//    {
//        sf::Vector2i mousePos = sf::Mouse::getPosition(*context.window);
//        sf::Vector2f worldPos = context.window->mapPixelToCoords(mousePos, view);
//        std::cout << worldPos.x << ' ' << worldPos.y << std::endl;
//
//        int temp = initialMousePos.x - mousePos.x;
//
//        view.move(static_cast<float>(initialMousePos.x - mousePos.x),
//                  static_cast<float>(initialMousePos.y - mousePos.y));
//        std::cout << temp;
//        if (temp % 2) temp += temp % 2;
//        std::cout << ' ' << temp << std::endl;
//
//        if (view.getCenter().y - view.getSize().y > 0) {
//            if (temp < 0) view.move(20, initialMousePos.y - mousePos.y);
//            else if (temp > 0) view.move(-20, initialMousePos.y - mousePos.y);
//        }
//
//        view.move(temp, initialMousePos.y - mousePos.y);
//
//        initialMousePos = mousePos;
//        view.setCenter(std::floor(view.getCenter().x), std::floor(view.getCenter().y));
//
//        if (view.getCenter().x - view.getSize().x / 2 < 0) view.setCenter(view.getSize().x / 2, view.getCenter().y);
//        else if(view.getCenter().x + view.getSize().x / 2 > windowSize.x) view.setCenter(windowSize.x- view.getSize().x / 2, view.getCenter().y);
//
//
//        if (view.getCenter().y - view.getSize().y / 2 < 0) view.setCenter(view.getCenter().x, view.getSize().y / 2);
//        else if (view.getCenter().y + view.getSize().y / 2 > windowSize.y) view.setCenter(view.getCenter().x, (windowSize.y - view.getSize().y / 2));
//
//        context.window->setView(view);
//    }


    sf::Vector2i mousePos = sf::Mouse::getPosition(*context.window);
    //std::cout << mousePos.x << ' ' << mousePos.y << std::endl;



//    std::cout << "view size : " << view.getSize().y << " X " << view.getSize().x << " " << std::endl;
//    std::cout << "center y: " << view.getCenter().y << "  center x: " << view.getCenter().x << std::endl;
    if (mousePos.x < 0) mousePos.x = 0;
    else if (mousePos.x > windowSize.x) mousePos.x = windowSize.x;

    if (mousePos.y < 0) mousePos.y = 0;
    else if (mousePos.y > windowSize.y) mousePos.y = windowSize.y;

    sf::Mouse::setPosition(mousePos, *context.window);

    if (mousePos.x == 0 && (view.getCenter().x - view.getSize().x / 2 > -5)) view.move(-300 * dt.asSeconds(), 0);
    else if (mousePos.x == windowSize.x && (view.getCenter().x + view.getSize().x / 2 < MAP_WIDTH * TILE_WIDTH + TILE_WIDTH / 2)) view.move(300 * dt.asSeconds(), 0);

    if (mousePos.y == 0 && (view.getCenter().y - view.getSize().y / 2 > -5)) view.move(0, -300 * dt.asSeconds());
    else if (mousePos.y == windowSize.y && (view.getCenter().y + view.getSize().y / 2 < MAP_HEIGHT / 2 * TILE_WIDTH / 2 + (MAP_HEIGHT - MAP_HEIGHT / 2) * TILE_HEIGHT + TILE_WIDTH / 2)) view.move(0, 300 * dt.asSeconds());

    context.window->setView(view);
}

void Camera::draw()
{
    float x = view.getCenter().x;
    float y = view.getCenter().y;

    x = std::floor(x);
    y = std::floor(y);

    std::cout << x << ' ' << y << std::endl;

    view.setCenter(x, y);
}

const sf::View &Camera::getView()
{
    return view;
}
