#include "GameState.h"

void ma::GameState::initialize(ma::GameEngine* pGameEngine)
{
    if (!m_initialized)
    {
        m_initialized = true;
        m_pGameEngine = pGameEngine;

        // call internal initialization method
        initialize();
    }
}

ma::GameEngine* ma::GameState::getEngine()
{
    return m_pGameEngine;
}
