#ifndef PIXED_CORE_GRAPHICS_GRAPHICSENTITY_HPP
#define PIXED_CORE_GRAPHICS_GRAPHICSENTITY_HPP

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../event/EventListener.hpp"

namespace engine
{

class GraphicsEntity : public EventListener, public sf::Drawable, public sf::Transformable
{
public:
    ///  Consturcts null GrpahicsEntity.
    ///  Object created using this c-tor should not be added to Scene if
    ///  setShape or setSprite not called, if so std::runtime_error raised.
    GraphicsEntity() = default;

    GraphicsEntity(sf::Shape* shape);
    GraphicsEntity(sf::Sprite* sprite);

    virtual ~GraphicsEntity();

    /// Sets sprite or shape model, previous instance will be deleted.
    void setShape(sf::Shape* shape);
    void setSprite(sf::Sprite* sprite);

    ///  If GraphicsEntity has shape model, returns pointer to sf::Shape, otherwise returns nullptr.
    sf::Shape* getShape() { return shape; }
    ///  If GraphicsEntity has sprite model, returns pointer to sf::Sprite, otherwise returns nullptr.
    sf::Sprite* getSprite() {return sprite; }

    // See comment below 'zIndex' variable.
    inline void setZIndex(int index) { this->zIndex = index; }
    inline int getZIndex() const { return zIndex; }

    // See comment below 'hidden' variable.
    inline bool isHidden() const { return hidden; }
    inline void setHidden(bool hidden) { this->hidden = hidden; }

    // See comment below 'disabled' variable.
    inline bool isDisabled() const { return disabled; }
    inline void setDisabled(bool disabled) { this->disabled = disabled; }

    sf::FloatRect getGlobalBounds();

    /// Trigger beforeMove, call sf::Transformable::Move and then trigger onMove.
    void move(const sf::Vector2f& offset);
    void move(float xOffset, float yOffset);
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ///  Called synchronously before move, if returns false -- no move performed.
    virtual bool beforeMove(const sf::Vector2f& /* offset */) { return true; }
    ///  Called right after entity moved.
    virtual void onMove(const sf::Vector2f& /* offset */) {};
    ///  Called after setHidden(true).
    virtual void onHide() {};
    ///  Called after setHidden(false).
    virtual void onShow() {};

private:
    sf::Shape* shape = nullptr;
    sf::Sprite* sprite = nullptr;

    bool disabled = false; ///<  If set to true, entity will not receive any events.
    bool hidden = false;   ///<  If set to true, entity will not be drawn at all.
    int zIndex = 0;        ///<  Z Index. Entities with higher index will be shown on top of entities with smaller index.
};

}

#endif // PIXED_CORE_GRAPHICS_GRAPHICSENTITY_HPP
