#include "GameObject.h"

void GameObject::update(float dt)
{
    for (auto pComponent : m_pComponents)
    {
        pComponent->update(dt);
    }
}

void GameObject::pollEvent(const sf::Event& event)
{
    for (auto pComponent : m_pComponents)
    {
        pComponent->pollEvent(event);
    }
}

GameObject::~GameObject()
{
    for (auto pComponent : m_pComponents)
    {
        delete pComponent;
    }
}

void GameObject::add(Component* pComponent)
{
    m_pComponents.push_back(pComponent);
}
