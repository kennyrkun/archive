#ifndef PIXED_CORE_EVENTLISTENER_HPP
#define PIXED_CORE_EVENTLISTENER_HPP

#include <SFML/Window/Event.hpp>
#include "Event.hpp"

namespace engine
{

class EventListener
{
    // Allow poller to call protected handlers.
    friend class EventPoller;
protected:
    EventListener();
    virtual ~EventListener();

    virtual void onTick() {}
    virtual void onEvent(const Event&) {}
};

}

#endif // PIXED_CORE_EVENTLISTENER_HPP
