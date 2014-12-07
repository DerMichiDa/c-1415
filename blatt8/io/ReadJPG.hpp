/**
 * @file ReadJPG.hpp
 * 
 * @author Michael Micke
 * @author Frank Mehne
 */

#ifndef READJPG_HPP_
#define READJPG_HPP_

#include <string>

namespace asteroids
{

class ReadJPG : public BitmapReader
{
public:
    /**
     * @brief loads a JPG file
     * @param filename File to be loaded by the ReadJPG instance
     */
    ReadJPG(const string filename);
}

} /* namespace asteriods */

#endif /* READJPG_HPP_ */
