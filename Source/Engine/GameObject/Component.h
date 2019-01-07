#ifndef RED_ARROW_COMPONENT_H
#define RED_ARROW_COMPONENT_H

#include <SFML/Window/Event.hpp>

#include "../Common/Updateable.h"
#include "GameObject.h"

namespace ma
{
    class GameObject;
    class Component;
}

class ma::Component : public ma::Updateable
{
public:

    explicit Component(GameObject* pParent);

    virtual ~Component();

    void update(float dt) override = 0;

    virtual void pollEvent(const sf::Event& event) = 0;

protected:
    GameObject* getParent();

private:
    GameObject* m_pParent;
};


#endif //RED_ARROW_COMPONENT_H
