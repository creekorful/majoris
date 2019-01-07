#ifndef MAJORIS_FONTMANAGER_H
#define MAJORIS_FONTMANAGER_H

#include <iostream>
#include <vector>
#include <map>

#include <SFML/Graphics/Font.hpp>

/**
 * Class to manage font loading / usage
 */
class FontManager
{
public:
    /**
     * Load font from given filePath
     *
     * @param filePath the font full file path
     */
    void loadFont(const std::string& filePath);

    /**
     * Get font using his name
     *
     * @param fontName the font to get name
     * @return reference to the font
     */
    sf::Font& getFont(const std::string& fontName);

private:
    std::map<std::string, sf::Font> m_pFonts;
};


#endif //MAJORIS_FONTMANAGER_H
