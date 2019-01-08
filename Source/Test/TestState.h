#ifndef MAJORIS_TESTSTATE_H
#define MAJORIS_TESTSTATE_H

#include "../Engine/State/GameState.h"
#include "../Engine/GameObject/Gui/Menu.h"

class TestState : public ma::GameState, public ma::IMenuCallback
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

    // Menu bindings

    void onMenuItemSelected(const std::string& itemName) override;

    void onMenuItemHovered(const std::string& itemName) override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void initialize() override;

private:
    sf::Font m_font;

    ma::Menu m_menu;
};


#endif //MAJORIS_TESTSTATE_H
