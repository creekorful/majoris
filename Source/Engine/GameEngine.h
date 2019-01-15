#ifndef RED_ARROW_GAMEENGINE_H
#define RED_ARROW_GAMEENGINE_H

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "State/GameState.h"
#include "Font/FontManager.h"
#include "Texture/TextureManager.h"

namespace ma
{
    class GameState;
    class GameEngine;
}

class GameState;

class ma::GameEngine
{
public:
    /**
     * Instantiate the game engine in full screen mode
     *
     * @param title the window title
     */
    explicit GameEngine(const std::string& title);

    /**
     * Instantiate the game engine
     *
     * @param videoMode the window video mode
     * @param title the window title
     */
    GameEngine(const sf::VideoMode& videoMode, const std::string& title);

    /**
     * Instantiate the game engine
     *
     * @param videoMode the window video mode
     * @param title the window title
     * @param style the window style
     */
    GameEngine(const sf::VideoMode& videoMode, const std::string& title, unsigned int style);

    /**
     * @return true if the game engine is running
     */
    bool isRunning();

    /**
     * execute the game engine main loop
     * make sure that there is an active state before calling execute otherwise app will crash
     */
    void execute();

    /**
     * Trigger game stop gracefully
     */
    void quit();

    /**
     * Set the current / active state
     *
     * @param pState pointer to the state
     */
    void setCurrentState(ma::GameState* pState);

    /**
     * @return current screen/window size
     */
    sf::Vector2u screenSize() const;

    /**
     * @return reference to font manager
     */
    ma::FontManager& fontManager();

    /**
     * @return reference to texture manager
     */
    ma::TextureManager& textureManager();

private:
    sf::RenderWindow m_window;
    GameState* m_pState;
    ma::FontManager m_fontManager;
    ma::TextureManager m_textureManager;
    sf::Clock m_deltaClock;
};


#endif //RED_ARROW_GAMEENGINE_H
