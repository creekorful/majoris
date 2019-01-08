#ifndef MAJORIS_TESTSTATE_H
#define MAJORIS_TESTSTATE_H


#include "../Engine/State/GameState.h"

class TestState : public ma::GameState
{
public:
    void update(float dt) override;

    void pollEvent(const sf::Event& event) override;

    std::string title() override;

    static TestState& instance()
    {
        static TestState instance;
        return instance;
    }

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void initialize() override;
};


#endif //MAJORIS_TESTSTATE_H
