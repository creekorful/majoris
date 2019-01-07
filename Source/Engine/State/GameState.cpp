#include "GameState.h"

void GameState::initialize(GameEngine* pGameEngine)
{
    if (!m_initialized)
    {
        m_initialized = true;
        m_pGameEngine = pGameEngine;

        // call internal initialization method
        initialize();
    }
}

GameEngine* GameState::getEngine()
{
    return m_pGameEngine;
}
