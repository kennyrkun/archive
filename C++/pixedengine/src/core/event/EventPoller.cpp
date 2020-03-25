#include "EventPoller.hpp"
#include "../Game.hpp"

pixed::EventPoller::EventPoller(std::shared_ptr<sf::RenderWindow> window)
    : window(window)
{
    // FIXME: Something goes wrong, when i put here something more than 1.
    scheduler.reserveThreads(1);
}

void pixed::EventPoller::broadcastEvents(std::queue<sf::Event> events)
{
    while (!events.empty()) {
        auto event = events.front(); events.pop();

        callbacks[event.type].broadcastEvent(event, scheduler);

        std::lock_guard<std::mutex> lock(listenersSetAccessMutex);
        for (EventListener* listener : listeners) {
            scheduler.schedule([listener, event]() { listener->onEvent(event); });
        }
    }
}

void pixed::EventPoller::onEvent(sf::Event::EventType type, pixed::EventPoller::CallbackFunc callback)
{
    callbacks[type].addCallback(callback);
}

void pixed::EventPoller::addListener(pixed::EventListener* listener)
{
    listeners.insert(listener);
}

void pixed::EventPoller::removeListener(pixed::EventListener* listener)
{
    auto it = listeners.find(listener);
    if (it != listeners.end())
        listeners.erase(it);
}

void pixed::EventPoller::pollEvents()
{
    while (this->window->isOpen()) {
        if (externalMutex)
            externalMutex->lock();
        sf::Event event;
        std::queue<sf::Event> eventsQueueBuffer;
        while (this->window->pollEvent(event)) {
            eventsQueueBuffer.push(event);
        }
        if (externalMutex)
            externalMutex->unlock();

        this->broadcastEvents(eventsQueueBuffer);

        {
            std::lock_guard<std::mutex> lock(listenersSetAccessMutex);
            for (EventListener* listener : listeners) {
                scheduler.schedule([listener]() { listener->onTick(); });
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

void pixed::EventPoller::CallbacksData::addCallback(pixed::EventPoller::CallbackFunc callback)
{
    std::lock_guard<std::mutex> lock(accessLock);
    callbacks.push_back(callback);
}

void pixed::EventPoller::CallbacksData::broadcastEvent(const sf::Event& event, pixed::ThreadScheduler& scheduler) const
{
    std::lock_guard<std::mutex> lock(accessLock);
    for (const CallbackFunc& callback : callbacks) {
        scheduler.schedule(callback, event);
    }
}
