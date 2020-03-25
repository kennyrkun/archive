#include "Scene.hpp"
#include <iostream>
#include <thread>
#include <chrono>

pixed::Scene::~Scene()
{
    this->clear();
}

void pixed::Scene::draw(sf::RenderWindow& targetWindow)
{
    std::lock_guard<std::mutex> lock(drawMutex);
    targetWindow.setActive(true);
    std::sort(entities.begin(), entities.end(),
              [](GraphicsEntity* a, GraphicsEntity* b)
              { return a->getZIndex() < b->getZIndex(); });

    targetWindow.clear(backgroundColor);

    for (const auto& entity : entities)
        if (!entity->isHidden())
            targetWindow.draw(*entity);

    targetWindow.display();
}

void pixed::Scene::addEntity(GraphicsEntity* entityPtr)
{
    entities.push_back(entityPtr);
}

void pixed::Scene::clear()
{
    // Don't allow to draw during cleaning.
    std::lock_guard<std::mutex> lock(drawMutex);
    for (GraphicsEntity* entity : entities) {
        delete entity;
        entity = nullptr;
    }
    entities.clear();
}
