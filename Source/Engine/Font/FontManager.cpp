#include "FontManager.h"

void ma::FontManager::loadFont(const std::string& filePath)
{
    sf::Font font;
    if (font.loadFromFile(filePath))
    {
        m_pFonts[font.getInfo().family] = font;
    }
}

sf::Font& ma::FontManager::getFont(const std::string& fontName)
{
    return m_pFonts.at(fontName);
}
