#ifndef PIXED_CORE_EVENT_EVENT_HPP
#define PIXED_CORE_EVENT_EVENT_HPP

#include <string>
#include <set>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

namespace engine
{

class Event
{
public:
    Event(const sf::Event& event);

    enum EventType
    {
        Unknown = 0,
        BoundKeyPress,
        BoundKeyRelease,
        UnboundKeyPress,
        UnboundKeyRelease,
        MousePress,
        MouseRelease
    } type;

    struct KeyEvent
    {
        std::set<std::string> boundIds;
        sf::Keyboard::Key rawCode;

        bool alt, control, shift, system;
    } keyEvent;

    struct MouseEvent
    {
        sf::Mouse::Button button;
        int x, y;
    } mouseEvent;

    const sf::Event rawEvent;
};

}

#endif // PIXED_CORE_EVENT_EVENT_HPP
