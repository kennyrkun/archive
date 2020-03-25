#include "Game.hpp"
#include <mutex>

std::shared_ptr<pixed::Game> pixed::Game::inst = nullptr;

pixed::Game::Game()
    : window(std::make_shared<sf::RenderWindow>())
    , poller(window)
{
    poller.onEvent(sf::Event::Closed, [this](const sf::Event&) { window->close(); });
    poller.externalMutex = &windowMutex;
}

void pixed::Game::rendererThreadEntry()
{
    while (window->isOpen()) {
        std::lock_guard<std::mutex> lock(windowMutex);
        if (currentScene)
            currentScene->draw(*window);
        else
            window->clear(sf::Color::Black);

//        ++framesDrawn;
//        if (std::time(nullptr) - prevTimestamp >= 1) {
//            prevTimestamp = std::time(nullptr);
//            framesPerSec = framesDrawn;
//            framesDrawn = 0;
//            std::clog << "FPS: " << framesPerSec << '\n';
//        }
        window->display();
    }
}

pixed::Game* pixed::Game::instance()
{
    static std::once_flag singletonInstanation;
    std::call_once(singletonInstanation, []() {
        inst = std::shared_ptr<Game>(new Game);
    });
    return inst.get();
}

void pixed::Game::run()
{
    window->setActive(false);
    std::thread renderThread(&Game::rendererThreadEntry, this);
    poller.pollEvents();
    renderThread.join();
}
