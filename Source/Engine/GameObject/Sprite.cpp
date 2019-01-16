#include "Sprite.h"

#include <iostream>
#include "SFML/Graphics/Texture.hpp"

ma::Sprite::Sprite() = default;

ma::Sprite::Sprite(const sf::Texture& texture, sf::Vector2f position)
{
    m_sprite.setTexture(texture);
    setPosition(position);
}

void ma::Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= transform();
    target.draw(m_sprite, states.transform);
}
