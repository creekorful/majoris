#ifndef RED_ARROW_GAMEOBJECT_H
#define RED_ARROW_GAMEOBJECT_H

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Component.h"

class Component;

/**
 * Game object base class
 * based on CBSE layout
 */
class GameObject : public Updateable, public sf::Drawable, public sf::Transformable
{
public:

    ~GameObject() override;

    /**
     * Update game object by given delta time
     *
     * @param dt the delta time
     */
    void update(float dt) override;

    void pollEvent(const sf::Event& event);

    /**
     * Add component to the game object
     *
     * @param pComponent pointer to the component to add
     */
    void add(Component* pComponent);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

private:
    std::vector<Component*> m_pComponents;
};


#endif //RED_ARROW_GAMEOBJECT_H
