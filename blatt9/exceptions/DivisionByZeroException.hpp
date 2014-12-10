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
class DivisionByZero : public BaseException
{

}

}

#endif /* DIVISION_BY_ZERO_HPP_ */
