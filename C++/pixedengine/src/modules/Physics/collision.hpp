/*
 * File:   collision.h
 * Authors: Nick Koirala (original version), ahnonay (SFML2 compatibility)
 *
 * Collision Detection and handling class
 * For SFML2.

Notice from the original version:

(c) 2009 - LittleMonkey Ltd

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,        YEP! It'S CHANGED!
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.

 *
 * Created on 30 January 2009, 11:02
 */

#ifndef PIXED_MODULE_PHYSICS_COLLISION_HPP
#define PIXED_MODULE_PHYSICS_COLLISION_HPP

#include <SFML/Graphics.hpp>

namespace pixed
{
namespace collision
{
    //////
    /// Test for a collision between two sprites by comparing the alpha values of overlapping pixels
    /// Supports scaling and rotation
    /// AlphaLimit: The threshold at which a pixel becomes "solid". If AlphaLimit is 127, a pixel with
    /// alpha value 128 will cause a collision and a pixel with alpha value 126 will not.
    ///
    /// This functions creates bitmasks of the textures of the two sprites by
    /// downloading the textures from the graphics card to memory -> SLOW!
    /// You can avoid this by using the "CreateTextureAndBitmask" function
    //////
    bool pixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
    bool pixelPerfectTest(const sf::Shape& Object1, const sf::Shape& Object2, sf::Uint8 AlphaLimit = 0);

    //////
    /// Replaces Texture::loadFromFile
    /// Load an imagefile into the given texture and create a bitmask for it
    /// This is much faster than creating the bitmask for a texture on the first run of "PixelPerfectTest"
    ///
    /// The function returns false if the file could not be opened for some reason
    //////
    bool createTextureAndBitmask(sf::Texture& LoadInto, const std::string& Filename);

    //////
    /// Test for collision using circle collision dection
    /// Radius is averaged from the dimensions of the sprite so
    /// roughly circular objects will be much more accurate
    //////
    bool circleTest(const sf::Sprite& object1, const sf::Sprite& object2);

    //////
    /// Test for bounding box collision using the Seperating Axis Theorem
    /// Supports scaling and rotation
    //////
    bool boundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
    bool boundingBoxTest(const sf::Shape& Object1, const sf::Shape& Object2);

    bool primitiveRectCollisionCheck(const sf::Sprite& object1, const sf::Sprite& object2);
    bool primitiveRectCollisionCheck(const sf::Shape& object1, const sf::Shape& object2);
} // namespace collision

namespace impl
{
class BitmaskManager {
public:
    ~BitmaskManager();
    sf::Uint8 getPixel(const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y);
    sf::Uint8* getMask(const sf::Texture* tex);
    sf::Uint8* createMask(const sf::Texture* tex, const sf::Image& img);

private:
    std::map<const sf::Texture*, sf::Uint8*> Bitmasks;
};

class OrientedBoundingBox // Used in the BoundingBoxTest
{
public:
    OrientedBoundingBox(const sf::Sprite& Object);
    OrientedBoundingBox(const sf::Shape& Object);
    sf::Vector2f Points[4];
    void projectOntoAxis(const sf::Vector2f& Axis, float& Min, float& Max);
};

bool boundingBoxTest(OrientedBoundingBox& OBB1, OrientedBoundingBox& OBB2);
bool primitiveRectCollisionCheck(sf::Vector2f size1, sf::Vector2f size2, sf::Vector2f pos1, sf::Vector2f pos2);
sf::Vector2f getSpriteCenter(const sf::Sprite& Object);
sf::Vector2f getSpriteSize(const sf::Sprite& Object);
sf::Vector2f getShapeSize(const sf::Shape& Object);
} // namespace impl

} // namespace pixed

#endif // PIXED_MODULE_PHYSICS_COLLISION_HPP
