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
    BitmapReader reader;
    Texture tex;
    // select adequate Reader by extension and load Bitmap
    if(filename.substr(filename.size()-4, 4)        == ".jpg")
    {
        reader = new ReadJPG(filename);
    }
    else if(filename.substr(filename()-4, 4)        == ".ppm")
    {
        reader = new ReadPPM(filename);
    }
    else if(filename.substr(filename.size()-4,4)    == ".tga")
    {
        reader = new ReadTGA(filename);
    }
    else if(filename.substr(filename.size()-5,5)    == ".tiff")
    {
        reader = new ReadTIFF(filename);
    }

    // load Texture
    tex = new Texture(reader.getPixels(), reader.getWidth(), reader.getHeight());
    return &tex;
}

void TextureFactory::setBasePath(const string &basepath)
{
    m_basepath = new string(basepath);
}
