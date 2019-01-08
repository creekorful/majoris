#ifndef MAJORIS_MENU_H
#define MAJORIS_MENU_H

#include <vector>

#include "../GameObject.h"
#include "Text.h"

namespace ma
{
    class Menu;

    class IMenuCallback;
}

class ma::IMenuCallback
{
public:
    virtual void onMenuItemSelected(const std::string& itemName) = 0;
    virtual void onMenuItemHovered(const std::string& itemName) = 0;
};

class ma::Menu : public ma::GameObject
{
public:

    Menu();

    void pollEvent(const sf::Event& event) override;

    void update(float dt) override;

    void setItems(const std::vector<std::string>& items, sf::Font& font);

    void setDefaultColor(const sf::Color& defaultColor);

    void setHighlightColor(const sf::Color& highlightColor);

    void setCallback(ma::IMenuCallback* pCallback);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::vector<ma::Text> m_items;
    sf::Color m_highlightColor;
    sf::Color m_defaultColor;
    ma::IMenuCallback* m_pCallback;
    int m_index;
};


#endif //MAJORIS_MENU_H
