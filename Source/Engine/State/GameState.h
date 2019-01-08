#ifndef RED_ARROW_GAMESTATE_H
#define RED_ARROW_GAMESTATE_H

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

#include "../Common/Updateable.h"
#include "../GameEngine.h"
#include "../GameObject/GameObject.h"

namespace ma
{
    class GameState;
    class GameEngine;
}

/**
 * A game state can be pause menu main menu single player mode etc...
 */
class ma::GameState : public ma::Updateable, public sf::Drawable
{
public:

    /**
     * Initialize the game state
     * called by game engine when select the game state for the first time
     * this will set internal pointer to game engine instance
     *
     * @param pGameEngine pointer to associated game engine
     */
    void initialize(ma::GameEngine* pGameEngine);

    /**
     * Update game state physics using given delta time
     * useful if physics should be computed
     *
     * @param dt the time passed
     */
    void update(float dt) override;

    /**
     * Poll event received from window
     *
     * @param event the event to poll / process
     */
    virtual void pollEvent(const sf::Event& event);

    /**
     * return the name of the state to be displayed on window title
     * if empty the window name will not be changed
     *
     * @return state window name or empty string
     */
    virtual std::string title() = 0;

protected:
    /**
     * Draw the state to the render target
     *
     * @param target the render target
     * @param states rend states to be used
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * called internally when first intialization occured
     * any initialization must be done here instead in the constructor to have
     * access to associated game engine
     */
    virtual void initialize() = 0;

    /**
     * Add game object to the state
     *
     * @param pointer to the game object to be added
     */
    void add(GameObject* gameObject);

    /**
     * @return the linked / associated game engine instance
     */
    GameEngine* getEngine();

private:
    GameEngine* m_pGameEngine;
    std::vector<ma::GameObject*> m_gameObjects;
    bool m_initialized;
};


#endif //RED_ARROW_GAMESTATE_H
