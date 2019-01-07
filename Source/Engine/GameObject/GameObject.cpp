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
