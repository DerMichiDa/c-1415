/**
 * @file BaseException.hpp
 * 
 * @author Frank Mehne
 * @author Michael Micke
 */

#ifndef BASE_EXCEPTION_HPP_
#define BASE_EXCEPTION_HPP_

#include <string>

namespace ansteroids
{

/**
 * @brief BaseException ist die Oberklasse für alle Exceptions, die im 
 *      asteroids-Projekt auftreten können.
 */
class BaseException
{
    string m_description;
public:
    BaseException() : BaseException("");
    /**
     * @brief Instanziiert ein neues BaseException Objekt.
     * @param descr eine Beschreibung mit wichtigen Informationen.
     *      Kann hinterher mittels what() wieder abgefragt werden.
     */
    BaseException(const string descr) : m_description(descr);
    /**
     * @brief Gibt eine Beschreibung der Exception zurück.
     */
    inline virtual const string what() const { return "BaseException: " + m_description };
}

}

#endif /* BASE_EXCEPTION_HPP_ */
