/**
 * @file OutOfBoundsException.hpp
 *
 * @author Michael Micke
 * @author Frank Mehne
 */

#ifndef OUT_OF_BOUNDS_EXCEPTION_HPP_
#define OUT_OF_BOUNDS_EXCEPTION_HPP_

#include "BaseException"

namespace asteroids
{

/**
 * @brief Eine Exception, die geworfen wird wenn versucht wird Indizes 
 *      abzufragen bzw. anzufordern, die außerhalb der Grenzen liegen.
 */
class OutOfBoundsException : public BaseException

}

#endif /* OUT_OF_BOUNDS_EXCEPTION_HPP_ */
