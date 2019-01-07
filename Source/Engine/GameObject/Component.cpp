#include "Component.h"

ma::Component::Component(GameObject* pParent)
{
    m_pParent = pParent;
}

ma::Component::~Component()
= default;

ma::GameObject* ma::Component::getParent()
{
    return m_pParent;
}
