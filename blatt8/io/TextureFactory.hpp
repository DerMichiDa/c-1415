/** 
 * @file TextureFactory.hpp
 * 
 * @author Frank Mehne
 * @author Michael Micke
 */

#ifndef TEXTURE_FACTORY_HPP
#define TEXTURE_FACTORY_HPP

#include <string>

namespace asteroids
{

/**
 * @brief Fabrikklasse für Texturen.
 */
class TextureFactory
{
    TextureFactory();
    static TextureFactory singleton;
    char* m_basepath
public:
    /**
     * @brief returns the singleton instance.
     */
    static TextureFactory* instance();
    /**
     * @brief loads a texture from the given file.
     *
     * @param filename don't give paths to the file (see TextureFactory::setBasePath)
     * @return Texture-Object
     */
    Texture* getTexture(const string &filename);
    /**
     * @brief sets the basepath to the texturefile
     * @desctiption 
     * The absolute basepath will be appended to the filename given to 
     * TextureFactory::getTexture.
     * @param basepath
     */
    void setBasePath(const string &basepath);
}

}

#endif
