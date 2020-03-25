#ifndef PIXED_PHYSICS_SOLIDENTITY_HPP
#define PIXED_PHYSICS_SOLIDENTITY_HPP

#include "../../core/graphics/GraphicsEntity.hpp"

namespace pixed
{

class SolidEntity : public GraphicsEntity
{
protected:
    virtual void onCollision(SolidEntity* /* otherEntity */) {}
    virtual bool beforeMove(const sf::Vector2f& offset) override;
};

}

#endif // PIXED_PHYSICS_SOLIDENTITY_HPP
