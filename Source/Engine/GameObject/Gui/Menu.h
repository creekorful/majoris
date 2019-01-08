#ifndef MAJORIS_MENU_H
#define MAJORIS_MENU_H

#include <vector>

#include "../GameObject.h"
#include "Text.h"

namespace ma::Gui
{
    class Menu;

    class IMenuCallback;
}

/**
 * Represent a callback to be used with menu
 */
class ma::Gui::IMenuCallback
{
public:

    /**
     * Triggered by menu when an item is selected (user press enter)
     *
     * @param itemName the menu item name
     */
    virtual void onMenuItemSelected(const std::string& itemName) = 0;

    /**
     * Triggered by menu when an item is hovered
     *
     * @param itemName the menu item name
     */
    virtual void onMenuItemHovered(const std::string& itemName) = 0;
};

/**
 * Represent a GUI menu with items
 */
class ma::Gui::Menu : public ma::GameObject
{
public:

    /**
     * Create an empty menu with no items
     */
    Menu();

    void pollEvent(const sf::Event& event) override;

    void update(float dt) override;

    /**
     * Set menu items
     *
     * @param items list of menu items
     * @param font font to use for menu
     */
    void setItems(const std::vector<std::string>& items, sf::Font& font);

    /**
     * Set menu default color (no highlighted entry)
     *
     * @param defaultColor the menu default color
     */
    void setDefaultColor(const sf::Color& defaultColor);

    /**
     * Set menu highlight color (color used when an entry is hovered)
     *
     * @param highlightColor menu highlight color
     */
    void setHighlightColor(const sf::Color& highlightColor);

    /**
     * Set menu associated callback
     *
     * @param pCallback pointer to menu callback
     */
    void setCallback(ma::Gui::IMenuCallback* pCallback);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::vector<ma::Gui::Text> m_items;
    sf::Color m_highlightColor;
    sf::Color m_defaultColor;
    ma::Gui::IMenuCallback* m_pCallback;
    int m_index;
};


#endif //MAJORIS_MENU_H
