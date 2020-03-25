#ifndef PIXED_CORE_EVENTPOLLER_HPP
#define PIXED_CORE_EVENTPOLLER_HPP

#include <vector>
#include <map>
#include <set>
#include <memory>
#include <mutex>
#include <iostream>
#include <thread>
#include <functional>
#include <SFML/Window.hpp>
#include "../../utils/threading/Semaphore.hpp"
#include "../../utils/threading/ThreadScheduler.hpp"
#include "../../core/graphics/Scene.hpp"

namespace engine
{

class EventPoller
{
    friend class EventListener;

    using CallbackFunc = std::function<void (sf::Event)>;
    class CallbacksData
    {
    public:
        void addCallback(CallbackFunc callback);
        void broadcastEvent(const sf::Event& event, ThreadScheduler& scheduler) const;

    private:
        mutable std::mutex accessLock;
        std::vector<CallbackFunc> callbacks;
    };

public:
    EventPoller(std::shared_ptr<sf::RenderWindow> window);

    void onEvent(sf::Event::EventType type, CallbackFunc callback);

    void addListener(EventListener* listener);
    void removeListener(EventListener* listener);

    /// Poll events until window is closed.
    void pollEvents();

    ThreadScheduler& getScheduler() { return scheduler; }
    std::mutex* externalMutex = nullptr;
private:
    void broadcastEvents(std::queue<sf::Event> events);

    std::map<sf::Event::EventType, CallbacksData> callbacks;
    std::shared_ptr<sf::RenderWindow> window;

    std::mutex listenersSetAccessMutex;
    std::set<EventListener*> listeners;

    ThreadScheduler scheduler;
};

}

#endif // PIXED_CORE_EVENTPOLLER_HPP
