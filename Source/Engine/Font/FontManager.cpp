#include "FontManager.h"

bool ma::FontManager::loadFont(const std::string& fontName, const std::string& filePath)
{
    sf::Font font;
    if (font.loadFromFile(filePath))
    {
        m_fonts[fontName] = font;
        return true;
    }

    return false;
}

sf::Font& ma::FontManager::getFont(const std::string& fontName)
{
    return m_fonts.at(fontName);
}