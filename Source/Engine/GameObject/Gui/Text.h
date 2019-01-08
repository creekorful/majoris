#ifndef MAJORIS_TEXT_H
#define MAJORIS_TEXT_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../GameObject.h"

namespace ma::Gui
{
    class Text;
}

/**
 * Basic game object that represent a text
 */
class ma::Gui::Text : public ma::GameObject
{
public:

    /**
     * Create an empty text
     */
    Text();

    /**
     * Create a text with following parameters
     *
     * @param font the text font
     * @param color the text fill color
     * @param text the text value
     * @param position the text position (relative to text center)
     */
    Text(sf::Font& font, sf::Color color, const std::string& text = "", const sf::Vector2f& position = sf::Vector2f());

    /**
     * @return the text value
     */
    std::string text() const;

    /**
     * @return the text fill color
     */
    sf::Color color() const;

    /**
     * Set the text value
     *
     * @param text the new text
     */
    void setText(const std::string& text);

    /**
     * Set the text fill color
     *
     * @param color the text fill color
     */
    void setColor(const sf::Color& color);

    /**
     * Set the text font
     *
     * @param font reference to text font
     */
    void setFont(sf::Font& font);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Text m_text;
};


#endif //MAJORIS_TEXT_H
