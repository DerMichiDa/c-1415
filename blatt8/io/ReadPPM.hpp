/**
 * @file ReadPPM.hpp
 *
 * @author Michael Micke
 * @author Frank Mehne
 */

#ifndef READ_PPM_HPP_
#define READ_PPM_HPP_

#include <string>

using std::string

namespace asteroids
{

class ReadPPM : public BitmapReader
{
public:
    /**
     * @brief constructor
     */
    ReadPPM(const string filename);
    /**
     * @brief destructor
     */
    ~ReadPPM(){};

    
}

} /* asteroids */

#endif /* READ_PPM_HPP_ */
