#ifndef MAJORIS_FONTMANAGER_H
#define MAJORIS_FONTMANAGER_H

#include <iostream>
#include <vector>
#include <map>

#include <SFML/Graphics/Font.hpp>


namespace ma
{
    class FontManager;
}

/**
 * Class to manage font loading / usage
 */
class ma::FontManager
{
public:
    /**
     * Load font from given filePath
     *
     * @param fontName the font name (used for later retrival)
     * @param filePath the font full file path
     * @return true if the font has been loaded false otherwise
     */
    bool loadFont(const std::string& fontName, const std::string& filePath);

    /**
     * Get font using his name
     * if the font is not found the behavior is undefined
     *
     * @param fontName the font to get name
     * @return reference to the font
     */
    sf::Font& getFont(const std::string& fontName);

private:
    std::map<std::string, sf::Font> m_fonts;
};


#endif //MAJORIS_FONTMANAGER_H
