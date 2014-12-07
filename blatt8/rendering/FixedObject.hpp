/**
 * @file FixedObject.hpp
 *
 * @author Frank Mehne
 * @æuthor Michael Micke
 */

#ifndef FIXED_OBJECT_HPP_
#define FIXED_OBJECT_HPP_

namespace asteroids
{

class FixedObject : public Randerable
{
protected:
    /// The width of the Object
    int m_width;
}

}

#endif /* FIXED_OBJECT_HPP_ */
