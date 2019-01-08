#include "GameState.h"

void ma::GameState::initialize(ma::GameEngine* pGameEngine)
{
    if (!m_initialized)
    {
        m_initialized = true;
        m_pGameEngine = pGameEngine;

        // call internal initialization method
        initialize();
    }
}

ma::GameEngine* ma::GameState::getEngine()
{
    return m_pGameEngine;
}

void ma::GameState::update(float dt)
{
    for (auto& gameObject : m_gameObjects)
    {
        gameObject->update(dt);
    }
}

void ma::GameState::pollEvent(const sf::Event& event)
{
    for (auto& gameObject : m_gameObjects)
    {
        gameObject->pollEvent(event);
    }
}

void ma::GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& gameObject : m_gameObjects)
    {
        target.draw(*gameObject, states);
    }
}

void ma::GameState::add(ma::GameObject* gameObject)
{
    m_gameObjects.push_back(gameObject);
}

void ma::GameState::reinitialize()
{
    // Delete game objects
    m_gameObjects.clear();

    m_initialized = false;
}
