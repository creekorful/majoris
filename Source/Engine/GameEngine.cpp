#include "GameEngine.h"

ma::GameEngine::GameEngine(const std::string& title)
        : GameEngine(sf::VideoMode::getFullscreenModes()[0], title, sf::Style::Fullscreen)
{
}

ma::GameEngine::GameEngine(const sf::VideoMode& videoMode, const std::string& title) :
        GameEngine(videoMode, title, sf::Style::Default)
{
}

ma::GameEngine::GameEngine(const sf::VideoMode& videoMode, const std::string& title, unsigned int style)
{
    // create window and setup
    m_window.create(videoMode, title, style);
    m_window.setFramerateLimit(60);

    // initialize members
    m_pState = nullptr;
}

bool ma::GameEngine::isRunning()
{
    return m_window.isOpen();
}

void ma::GameEngine::execute()
{
    // first of all poll events
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        // manage window quit event
        if (event.type == sf::Event::Closed)
        {
            quit();
        }

        m_pState->pollEvent(event);
    }

    // clear window
    m_window.clear();

    // then update physics for current state
    sf::Time dt = m_deltaClock.restart();
    m_pState->update(dt.asMilliseconds());

    // finally render state to screen
    m_window.draw(*m_pState);

    // render everything to the screen
    m_window.display();
}

void ma::GameEngine::setCurrentState(ma::GameState* pState)
{
    // If there is a previous state that should be reinitialized
    if (m_pState != nullptr)
    {
        if (m_pState->shouldReinitialize())
        {
            m_pState->reinitialize();
        }
    }

    m_pState = pState;
    m_pState->initialize(this);

    // override window title if any
    if (pState->title().empty())
    {
        m_window.setTitle(pState->title());
    }
}

void ma::GameEngine::quit()
{
    m_window.close();
}

sf::Vector2u ma::GameEngine::screenSize() const
{
    return m_window.getSize();
}

ma::FontManager& ma::GameEngine::fontManager()
{
    return m_fontManager;
}
