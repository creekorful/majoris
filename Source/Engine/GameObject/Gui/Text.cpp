#include "Text.h"

ma::Gui::Text::Text() = default;

ma::Gui::Text::Text(sf::Font& font, sf::Color color, const std::string& text, const sf::Vector2f& position)
{
    m_text.setFont(font);
    m_text.setFillColor(color);

    // Before setting position set text origin at text middle
    setText(text);

    m_text.setPosition(position);
}

void ma::Gui::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_text, states);
}

std::string ma::Gui::Text::text() const
{
    return m_text.getString();
}

sf::Color ma::Gui::Text::color() const
{
    return m_text.getFillColor();
}

void ma::Gui::Text::setText(const std::string& text)
{
    m_text.setString(text);

    // Update text origin to center based on text size
    sf::FloatRect rect = m_text.getLocalBounds();
    m_text.setOrigin(rect.left + rect.width / 2, rect.top + rect.height / 2);
}

void ma::Gui::Text::setColor(const sf::Color& color)
{
    m_text.setFillColor(color);
}

void ma::Gui::Text::setFont(sf::Font& font)
{
    m_text.setFont(font);
}
