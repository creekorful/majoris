#include "TextureManager.h"

bool ma::TextureManager::loadTexture(const std::string& textureName, const std::string& filePath)
{
    sf::Texture texture;

    if (texture.loadFromFile(filePath))
    {
        m_textures[textureName] = texture;
        return true;
    }

    return false;
}

sf::Texture& ma::TextureManager::getTexture(const std::string& textureName)
{
    return m_textures.at(textureName);
}
