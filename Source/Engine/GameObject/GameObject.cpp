#include "GameObject.h"

void ma::GameObject::update(float dt)
{
    for (auto pComponent : m_pComponents)
    {
        pComponent->update(dt);
    }
}

void ma::GameObject::pollEvent(const sf::Event& event)
{
    for (auto pComponent : m_pComponents)
    {
        pComponent->pollEvent(event);
    }
}

ma::GameObject::~GameObject()
{
    for (auto pComponent : m_pComponents)
    {
        delete pComponent;
    }
}

void ma::GameObject::add(Component* pComponent)
{
    m_pComponents.push_back(pComponent);
}

void ma::GameObject::setPosition(sf::Vector2f position)
{
    m_transform.setPosition(position);
}

void ma::GameObject::setPosition(float x, float y)
{
    m_transform.setPosition(x, y);
}

sf::Vector2f ma::GameObject::position() const
{
    return m_transform.getPosition();
}

sf::Transform ma::GameObject::transform() const
{
    return m_transform.getTransform();
}

void ma::GameObject::setOrigin(float x, float y)
{
    m_transform.setOrigin(x, y);
}
