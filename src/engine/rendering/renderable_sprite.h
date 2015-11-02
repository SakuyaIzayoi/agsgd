// renderer.h
#ifndef DEFINED_RENDERER
#define DEFINED_RENDERER

#include <SFML/Graphics.hpp>

namespace StevensDev
{

namespace sgdr
{

class RenderableSprite
{
  private:
    sf::Sprite d_sprite;
  public:
    const sf::Sprite& sprite() const;
    void setPosition( float x, float y );
    float getPositionX();
    float getPositionY();
    void move( float x, float y );
};

}

}
#endif
