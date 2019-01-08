#include "TestState.h"

void TestState::update(float dt)
{
    m_menu.update(dt);
}

void TestState::pollEvent(const sf::Event& event)
{
    m_menu.pollEvent(event);
}

std::string TestState::title()
{
    return "Majoris - Test state";
}

void TestState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_menu, states);
}

void TestState::initialize()
{
    // Load arial font and keep reference to it
    getEngine()->fontManager().loadFont("Fonts/Arial.ttf");
    m_font = getEngine()->fontManager().getFont("Arial");

    sf::Vector2u screenSize = getEngine()->screenSize();

    // Create dummy menu at screen center
    m_menu.setDefaultColor(sf::Color::Yellow);
    m_menu.setHighlightColor(sf::Color::Red);
    m_menu.setItems({"Singleplayer", "Multiplayer", "Options", "Exit"}, m_font);
    m_menu.setPosition(screenSize.x / 2.f, screenSize.y / 2.f);
    m_menu.setCallback(this);
}

void TestState::onMenuItemSelected(const std::string& itemName)
{
    if (itemName == "Exit")
    {
        getEngine()->quit();
    }
}

void TestState::onMenuItemHovered(const std::string& itemName)
{
}
