#include "SolidEntity.hpp"
#include <memory>
#include "../../core/Game.hpp"

bool pixed::SolidEntity::beforeMove(const sf::Vector2f& offset)
{
    for (auto entity : GAME->getCurrentscene()->getEntities()) {
        if (dynamic_cast<SolidEntity*>(entity) == nullptr || entity == this)
            continue;

        sf::FloatRect rect1 = this->getGlobalBounds(), rect2 = entity->getGlobalBounds();
        rect1.left += offset.x;
        rect1.top  += offset.y;

        if (entity->getZIndex() == this->getZIndex()) {
            if (rect1.intersects(rect2)) {
                {
                    // Move entity as much as possible to collided entity.

                }

                GAME->getPoller().getScheduler().schedule([entity, this]() {
                    this->onCollision(dynamic_cast<SolidEntity*>(entity));
                });

                return false;
            }
        }
    }
    return true;
}
