#include "Event.hpp"
#include "../Game.hpp"

pixed::Event::Event(const sf::Event& event)
    : rawEvent(event)
{
    switch (event.type) {
    case sf::Event::KeyPressed:
    case sf::Event::KeyReleased:
        if (GAME->getKeymap().getBoundKeys(event.key.code).empty()) {
            type = event.type == sf::Event::KeyPressed ? UnboundKeyPress : UnboundKeyRelease;
        } else {
            type = event.type == sf::Event::KeyPressed ? BoundKeyPress : BoundKeyRelease;
            keyEvent.boundIds = GAME->getKeymap().getBoundKeys(event.key.code);
        }
        keyEvent.rawCode = event.key.code;
        keyEvent.alt     = event.key.alt;
        keyEvent.control = event.key.control;
        keyEvent.shift   = event.key.shift;
        keyEvent.system  = event.key.system;
        break;
    case sf::Event::MouseButtonPressed:
        type = MousePress;
        mouseEvent.button = event.mouseButton.button;
        mouseEvent.x = event.mouseButton.x;
        mouseEvent.y = event.mouseButton.y;
        break;
    case sf::Event::MouseButtonReleased:
        type = MouseRelease;
        mouseEvent.button = event.mouseButton.button;
        mouseEvent.x = event.mouseButton.x;
        mouseEvent.y = event.mouseButton.y;
        break;
    default: type = Unknown; break;
    }
}
