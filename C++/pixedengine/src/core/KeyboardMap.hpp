#ifndef PIXED_CORE_KEYBOARDMAP_HPP
#define PIXED_CORE_KEYBOARDMAP_HPP

#include <string>
#include <map>
#include <set>
#include <SFML/Window/Keyboard.hpp>

namespace engine
{

class KeyboardMap
{
public:
    void addBinding(sf::Keyboard::Key key, const std::string& id);
    const std::set<std::string>& getBoundKeys(sf::Keyboard::Key key);
    const std::map<sf::Keyboard::Key, std::set<std::string>>& getBoundKeys() const;

private:
    std::map<sf::Keyboard::Key, std::set<std::string>> boundKeys;

};

}

#endif
