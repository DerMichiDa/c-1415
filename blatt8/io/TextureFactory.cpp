/** 
 * @file TextureFactory.hpp
 * 
 * @author Frank Mehne
 * @author Michael Micke
 */

#include "TextureFactory.hpp"

#include <string>
#include "BitmapReader.hpp"
#include "ReadTGA.hpp"
#include "ReadTIFF.hpp"

namespace asteroids
{

static TextureFactory* TextureFactory::instance()
{
    if(singleton == 0) singleton = new TextureFactory();
    return singleton;
}

Texture* TextureFactory::getTexture(const string &filename)
{
    
}

void TextureFactory::setBasePath(const string &basepath)
{
    m_basepath = new string(basepath);
}
