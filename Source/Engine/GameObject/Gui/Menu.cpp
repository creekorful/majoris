#include "Menu.h"

ma::Menu::Menu()
{
    m_index = 0;
    m_pCallback = nullptr;
}

void ma::Menu::pollEvent(const sf::Event& event)
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

void ma::Menu::update(float dt)
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

void ma::Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& text : m_items)
    {
        // todo maybe manage relative position
        //states.transform *= getTransform();
        target.draw(text, states);
    }
}

void ma::Menu::setItems(const std::vector<std::string>& items, sf::Font& font)
{
    int index = 0;
    for (const std::string& item : items)
    {
        ma::Text text;
        text.setColor(m_defaultColor);
        text.setText(item);
        text.setFont(font);
        text.setPosition(getPosition().x, getPosition().y + (index * 50));

        m_items.push_back(text);
        index++;
    }
}

void ma::Menu::setDefaultColor(const sf::Color& defaultColor)
{
    m_defaultColor = defaultColor;
}

void ma::Menu::setHighlightColor(const sf::Color& highlightColor)
{
    m_highlightColor = highlightColor;
}

void ma::Menu::setCallback(ma::IMenuCallback* pCallback)
{
    m_pCallback = pCallback;
}
