#include "EventListener.hpp"
#include "../Game.hpp"

pixed::EventListener::EventListener()
{
    std::lock_guard<std::mutex>(GAME->getPoller().listenersSetAccessMutex);
    GAME->getPoller().addListener(this);
}

pixed::EventListener::~EventListener()
{
    std::lock_guard<std::mutex>(GAME->getPoller().listenersSetAccessMutex);
    GAME->getPoller().removeListener(this);
}
