#ifndef MAJORIS_TEXTUREMANAGER_H
#define MAJORIS_TEXTUREMANAGER_H

#include <map>

#include <SFML/Graphics/Texture.hpp>

namespace ma
{
    class TextureManager;
}

/**
 * Class to manage texture loading / usage
 * to prevent multiple texture loading and thus high memory usage
 */
class ma::TextureManager
{
public:

    /**
     * Load texture from given file path and store it as textureName
     *
     * @param textureName the texture name (used for later retrieval)
     * @param filePath the texture file path
     * @return true if the texture has been loaded false otherwise
     */
    bool loadTexture(const std::string& textureName, const std::string& filePath);

    /**
     * Get reference to loaded texture using his name
     * if the texture is not found the behavior is undefined
     *
     * @param textureName the texture name
     * @return reference to the texture
     */
    sf::Texture& getTexture(const std::string& textureName);

private:
    std::map<std::string, sf::Texture> m_textures;
};


#endif //MAJORIS_TEXTUREMANAGER_H
