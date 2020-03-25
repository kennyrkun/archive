#include "KeyboardMap.hpp"

void pixed::KeyboardMap::addBinding(sf::Keyboard::Key key, const std::string& id)
{
    boundKeys[key].insert(id);
}

const std::set<std::string>& pixed::KeyboardMap::getBoundKeys(sf::Keyboard::Key key)
{
    return boundKeys[key];
}

const std::map<sf::Keyboard::Key, std::set<std::string> >& pixed::KeyboardMap::getBoundKeys() const
{
    return boundKeys;
}
