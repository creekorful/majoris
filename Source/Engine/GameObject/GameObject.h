#ifndef RED_ARROW_GAMEOBJECT_H
#define RED_ARROW_GAMEOBJECT_H

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Component.h"

namespace ma
{
    class Component;

    class GameObject;
}

/**
 * Game object base class
 * based on CBSE layout
 */
class ma::GameObject : public ma::Updateable, public sf::Drawable
{
public:

    ~GameObject() override;

    /**
     * Update game object by given delta time
     *
     * @param dt the delta time
     */
    void update(float dt) override;

    virtual void pollEvent(const sf::Event& event);

    /**
     * Add component to the game object
     *
     * @param pComponent pointer to the component to add
     */
    void add(Component* pComponent);

    /**
     * Set game object position
     *
     * @param position the game object position
     */
    virtual void setPosition(sf::Vector2f position);

    /**
     * Set game object position
     *
     * @param x position on x-axis
     * @param y position on y-axis
     */
    virtual void setPosition(float x, float y);

    /**
     * @return game object transform
     */
    sf::Transform transform() const;

    /**
     * @return game object position
     */
    sf::Vector2f position() const;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

    /**
     * set game object transform origin
     *
     * @param x x position of transform
     * @param y y position of transform
     */
    void setOrigin(float x, float y);

private:
    std::vector<Component*> m_pComponents;

    sf::Transformable m_transform;
};


#endif //RED_ARROW_GAMEOBJECT_H
