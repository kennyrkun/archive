#ifndef PIXED_CORE_GRAPHICS_SCENE_HPP
#define PIXED_CORE_GRAPHICS_SCENE_HPP

#include <vector>
#include <memory>
#include <mutex>
#include <queue>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GraphicsEntity.hpp"

namespace engine
{

class Scene
{
public:
    ~Scene();

    void draw(sf::RenderWindow& targetWindow);
    void addEntity(GraphicsEntity* entityPtr);

    void setBackgroundColor(sf::Color newColor) { backgroundColor = newColor; }
    sf::Color getBackgroundColor() const { return backgroundColor; }

    std::vector<GraphicsEntity*>& getEntities() { return entities; }
    const std::vector<GraphicsEntity*>& getEntities() const { return entities; }

    /// Removes all entities from scene.
    void clear();
private:
    std::vector<GraphicsEntity*> entities;
    sf::Color backgroundColor = sf::Color::Black;

    std::mutex drawMutex;
};

}

#endif // PIXED_CORE_GRAPHICS_SCENE_HPP
