#include "GraphicsEntity.hpp"
#include <cassert>
#include "../Game.hpp"

pixed::GraphicsEntity::GraphicsEntity(sf::Shape* shape)
    : shape(shape)
{
}

pixed::GraphicsEntity::GraphicsEntity(sf::Sprite* sprite)
    : sprite(sprite)
{
}

pixed::GraphicsEntity::~GraphicsEntity()
{
    if (sprite)
        delete sprite;
    if (shape)
        delete shape;
}

void pixed::GraphicsEntity::setShape(sf::Shape* shape)
{
    assert(shape);
    if (sprite) {
        delete sprite;
        sprite = nullptr;
    }
    this->shape = shape;
}

void pixed::GraphicsEntity::setSprite(sf::Sprite* sprite)
{
    assert(sprite);
    if (this->shape) {
        delete this->shape;
        this->shape = nullptr;
    }
    this->sprite = sprite;
}

sf::FloatRect pixed::GraphicsEntity::getGlobalBounds()
{
    sf::FloatRect rect;
    if (this->getShape()) {
        rect = this->getShape()->getGlobalBounds();
    } else if (this->getSprite()) {
        rect = this->getSprite()->getGlobalBounds();
    } else {
        return sf::FloatRect();
    }

    sf::Vector2f pos = this->getPosition();
    return sf::FloatRect(pos, { rect.width, rect.height });
}

void pixed::GraphicsEntity::move(const sf::Vector2f& offset)
{
    if (!this->beforeMove(offset)) {
        return;
    }
    sf::Transformable::move(offset);
    GAME->getPoller().getScheduler().schedule(std::bind(&GraphicsEntity::onMove, this, offset));
}

void pixed::GraphicsEntity::move(float xOffset, float yOffset)
{
    if (!this->beforeMove({ xOffset, yOffset })) {
        return;
    }
    sf::Transformable::move(xOffset, yOffset);
    GAME->getPoller().getScheduler().schedule(std::bind(&GraphicsEntity::onMove, this, sf::Vector2f{ xOffset, yOffset }));
}

void pixed::GraphicsEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = this->getTransform();
    if (shape)
        target.draw(*shape, states);
    else if (sprite)
        target.draw(*sprite, states);
    else
        throw std::runtime_error("draw called for null GraphicsEntity.");
}
