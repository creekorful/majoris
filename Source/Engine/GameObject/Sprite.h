#ifndef MAJORIS_SPRITE_H
#define MAJORIS_SPRITE_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameObject.h"

namespace ma
{
    class Sprite;
}

class ma::Sprite : public ma::GameObject
{
public:

    Sprite();

    Sprite(const sf::Texture& texture, sf::Vector2f position);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite m_sprite;
};


#endif //MAJORIS_SPRITE_H
