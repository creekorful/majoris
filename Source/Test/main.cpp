#include <iostream>
#include "../Engine/GameEngine.h"
#include "TestState.h"

int main()
{
    ma::GameEngine* pEngine = new ma::GameEngine(sf::VideoMode(800, 600), "Majoris Test");
    pEngine->setCurrentState(&TestState::instance());

    while (pEngine->isRunning())
    {
        pEngine->execute();
    }

    return 0;
}