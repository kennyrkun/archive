#include "ControllableEntity.hpp"
#include <iostream>

pixed::ControllableEntity::ControllableEntity()
{
}

void pixed::ControllableEntity::onTick()
{
    this->move((right - left) * speedMult, (down - up) * speedMult);
}

void pixed::ControllableEntity::onEvent(const Event& event)
{
    if (event.type == Event::BoundKeyPress) {
             if (event.keyEvent.boundIds.find("up")    != event.keyEvent.boundIds.end()) up    = true;
        else if (event.keyEvent.boundIds.find("down")  != event.keyEvent.boundIds.end()) down  = true;
        else if (event.keyEvent.boundIds.find("left")  != event.keyEvent.boundIds.end()) left  = true;
        else if (event.keyEvent.boundIds.find("right") != event.keyEvent.boundIds.end()) right = true;
    } else if (event.type == Event::BoundKeyRelease) {
             if (event.keyEvent.boundIds.find("up")    != event.keyEvent.boundIds.end()) up    = false;
        else if (event.keyEvent.boundIds.find("down")  != event.keyEvent.boundIds.end()) down  = false;
        else if (event.keyEvent.boundIds.find("left")  != event.keyEvent.boundIds.end()) left  = false;
        else if (event.keyEvent.boundIds.find("right") != event.keyEvent.boundIds.end()) right = false;
    } else if (event.rawEvent.type == sf::Event::LostFocus) {
        up    = false;
        down  = false;
        left  = false;
        right = false;
    }
}
