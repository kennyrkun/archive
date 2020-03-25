#include <thread>
#include <iostream>

#include "core/Game.hpp"
#include "modules/ControllableEntity/ControllableEntity.hpp"
#include "modules/Physics/SolidEntity.hpp"

using namespace engine;

int main()
{
    GAME->setCurrentScene(std::make_shared<Scene>());
    GAME->getCurrentscene()->setBackgroundColor(sf::Color::Green);

    GAME->getKeymap().addBinding(sf::Keyboard::W, "up");
    GAME->getKeymap().addBinding(sf::Keyboard::S, "down");
    GAME->getKeymap().addBinding(sf::Keyboard::A, "left");
    GAME->getKeymap().addBinding(sf::Keyboard::D, "right");

    GAME->getWindow()->setFramerateLimit(60);

    {
        SolidEntity* box = new SolidEntity();
        box->setShape(new sf::RectangleShape({100, 100}));
        box->setPosition({200, 200});
        box->getShape()->setFillColor(sf::Color::Red);
        GAME->getCurrentscene()->addEntity(box);
    }

    {
        ControllableEntity* entity = new ControllableEntity();
        entity->setShape(new sf::RectangleShape({50, 50}));
        entity->setPosition({25, 25});
        entity->getShape()->setFillColor(sf::Color::Black);
        entity->getShape()->setOutlineColor(sf::Color::Cyan);
        GAME->getCurrentscene()->addEntity(entity);
    }

    GAME->createWindow(sf::VideoMode(900, 900), "Title");

    GAME->run();
}
