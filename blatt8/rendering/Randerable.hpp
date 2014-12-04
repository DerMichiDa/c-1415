/**
 * @file Randerable.hpp
 *
 * @date 04.12.2014
 * @author Michael Micke
 * @author Frank Mehne
 */

#ifndef RANDERABLE_HPP_
#define RANDERABLE_HPP_

namespace asteroids
{

class Randerable
{
public:
    /**
     * @brief Renders the mesh
     * @description 
     * Renderable::render() is a pure virtual method that is to be implemented
     * in a subclass of Randerable.
     */
    virtual void render() = 0;
}

}

#endif//ifndef RANDERABLE_HPP
