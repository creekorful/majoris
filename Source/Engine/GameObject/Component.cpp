#include "Component.h"

Component::Component(GameObject* pParent)
{
    m_pParent = pParent;
}

Component::~Component()
= default;

GameObject* Component::getParent()
{
    return m_pParent;
}
