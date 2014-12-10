/**
 * @file DivisionByZero.hpp
 *
 * @author Frank Mehne
 * @author Michael Micke
 */

#ifndef DIVISION_BY_ZERO_HPP_
#define DIVISION_BY_ZERO_HPP_

namespace asteroids
{

/**
 * @brief Exception, die immer dann auftritt, wenn versucht wird durch Null
 *      zu teilen. (Verboten!!!)
 */
class DivisionByZeroException : public BaseException
{
public:
    inline virtual const string what() const { return "DivisionByZeroExcpetion: " + m_description; }
}

}

#endif /* DIVISION_BY_ZERO_HPP_ */
