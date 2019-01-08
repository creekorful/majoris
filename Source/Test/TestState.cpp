#include "TestState.h"

void TestState::update(float dt)
{
}

void TestState::pollEvent(const sf::Event& event)
{
}

std::string TestState::title()
{
    return "Majoris - Test state";
}

void TestState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}

void TestState::initialize()
{
    // Load arial font and keep reference to it
    getEngine()->fontManager().loadFont("Fonts/Arial.ttf");
    m_font = getEngine()->fontManager().getFont("Arial");

    sf::Vector2u screenSize = getEngine()->screenSize();

    // Create dummy text at screen center
    m_text.setFont(m_font);
    m_text.setText("This is a test string :D");
    m_text.setColor(sf::Color::Yellow);
    m_text.setPosition(screenSize.x /2 , screenSize.y / 2);
}
