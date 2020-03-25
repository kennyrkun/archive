#ifndef PIXED_MODULE_CONTROLLABLEENTITY_HPP
#define PIXED_MODULE_CONTROLLABLEENTITY_HPP

#include <atomic>
#include "../../core/graphics/GraphicsEntity.hpp"
#include "../Physics/SolidEntity.hpp"

namespace engine
{

class ControllableEntity : public SolidEntity
{
public:
    ControllableEntity();

    virtual void onTick() override;
    virtual void onEvent(const Event& event) override;

private:
    int speedMult = 1;
    bool up = false, down = false, left = false, right = false;
    std::atomic<int> moveX, moveY;
};

}

#endif // PIXED_MODULE_CONTROLLABLEENTITY_HPP
