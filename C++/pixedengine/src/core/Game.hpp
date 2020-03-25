#ifndef PIXED_CORE_GAME_HPP
#define PIXED_CORE_GAME_HPP

#include <mutex>
#include <memory>
#include "KeyboardMap.hpp"
#include "event/EventPoller.hpp"
#include "graphics/Scene.hpp"

namespace engine
{

#define GAME (Game::instance())

class Game
{
public:
    static Game* instance();

    Game(const Game&) = delete;
    Game(Game&&) = delete;

    KeyboardMap& getKeymap() { return keymap; }
    EventPoller& getPoller() { return poller; }
    std::shared_ptr<Scene> getCurrentscene() { return currentScene; }
    void setCurrentScene(std::shared_ptr<Scene> newScene) { currentScene = newScene; }
    std::shared_ptr<sf::RenderWindow> getWindow() { return window; }

    template<typename... Args>
    void createWindow(Args... args) { window->create(args...); }
    void run();

private:
    Game();
    static std::shared_ptr<Game> inst;
    void rendererThreadEntry();

    std::shared_ptr<Scene> currentScene;
    std::shared_ptr<sf::RenderWindow> window;

    std::mutex windowMutex;

    KeyboardMap keymap;
    EventPoller poller;
};

}

#endif // PIXED_CORE_GAME_HPP
