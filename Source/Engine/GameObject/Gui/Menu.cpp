#include "Menu.h"

ma::Gui::Menu::Menu()
{
    m_index = 0;
    m_pCallback = nullptr;
}

void ma::Gui::Menu::pollEvent(const sf::Event& event)
{
    GameObject::pollEvent(event);

    // Manage event that may be related to menu
    if (event.type == sf::Event::KeyPressed)
    {
        // Up in menu
        if (event.key.code == sf::Keyboard::Z && m_index > 0)
        {
            m_index--;

            if (m_pCallback != nullptr)
            {
                m_pCallback->onMenuItemHovered(m_items[m_index].text());
            }
        }

        // Down in menu
        if (event.key.code == sf::Keyboard::S && m_index < m_items.size() - 1)
        {
            m_index++;

            if (m_pCallback != nullptr)
            {
                m_pCallback->onMenuItemHovered(m_items[m_index].text());
            }
        }

        // Item choosen
        if (event.key.code == sf::Keyboard::Return)
        {
            if (m_pCallback != nullptr)
            {
                m_pCallback->onMenuItemSelected(m_items[m_index].text());
            }
        }
    }
}

void ma::Gui::Menu::update(float dt)
{
    GameObject::update(dt);

    // Update text colors
    for (int iItem = 0; iItem < m_items.size(); iItem++)
    {
        if (iItem == m_index)
        {
            m_items[iItem].setColor(m_highlightColor);
        }

        else
        {
            m_items[iItem].setColor(m_defaultColor);
        }
    }

}

void ma::Gui::Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= transform();

    for (const auto& text : m_items)
    {
        target.draw(text, states);
    }
}

void ma::Gui::Menu::setItems(const std::vector<std::string>& items, sf::Font& font)
{
    int index = 0;
    for (const std::string& item : items)
    {
        ma::Gui::Text text;
        text.setColor(m_defaultColor);
        text.setText(item);
        text.setFont(font);
        text.setPosition(0, index * 50);

        m_items.push_back(text);
        index++;
    }
}

void ma::Gui::Menu::setDefaultColor(const sf::Color& defaultColor)
{
    m_defaultColor = defaultColor;
}

void ma::Gui::Menu::setHighlightColor(const sf::Color& highlightColor)
{
    m_highlightColor = highlightColor;
}

void ma::Gui::Menu::setCallback(ma::Gui::IMenuCallback* pCallback)
{
    m_pCallback = pCallback;
}

void ma::Gui::Menu::setPosition(sf::Vector2f position)
{
    setPosition(position.x, position.y);
}

void ma::Gui::Menu::setPosition(float x, float y)
{
    // Compute position based on menu size
    sf::Vector2f menuSize;

    if (!m_items.empty())
    {
        // x size is determinate by longest menu entry
        for (const auto& entry : m_items)
        {
            float size = entry.globalBounds().width;

            if (size > menuSize.x)
            {
                menuSize.x = size;
            }
        }

        // y size is equals to (number of items * item height) + (spacing * number of items - 1)
        menuSize.y = m_items.at(0).globalBounds().height * m_items.size();
        menuSize.y += 50 * (m_items.size() - 1);
    }

    setOrigin(menuSize.x / 2, menuSize.y / 2);
    GameObject::setPosition(x, y);
}
