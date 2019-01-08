#include "Text.h"

ma::Text::Text() = default;

ma::Text::Text(sf::Font& font, sf::Color color, const std::string& text, const sf::Vector2f& position)
{
    m_text.setFont(font);
    m_text.setFillColor(color);

    // Before setting position set text origin at text middle
    setText(text);

    m_text.setPosition(position);
}

void ma::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_text, states);
}

std::string ma::Text::text() const
{
    return m_text.getString();
}

sf::Color ma::Text::color() const
{
    return m_text.getFillColor();
}

void ma::Text::setText(const std::string& text)
{
    m_text.setString(text);

    // Update text origin to center based on text size
    sf::FloatRect rect = m_text.getLocalBounds();
    m_text.setOrigin(rect.left + rect.width / 2, rect.top + rect.height / 2);
}

void ma::Text::setColor(const sf::Color& color)
{
    m_text.setFillColor(color);
}

void ma::Text::setFont(sf::Font& font)
{
    m_text.setFont(font);
}
