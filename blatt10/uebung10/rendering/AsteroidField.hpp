
#ifndef ASTEROIDFIELD_HPP_
#define ASTEROIDFIELD_HPP_

#include <cmath>
#include <algorithm>
#include <vector>

#include "Asteroid.hpp"
#include "FixedObject.hpp"
#include "math/Vertex.hpp"
#include "List.hpp"

using std::for_each;
using std::vector;
using std::generate;

namespace asteroids
{


class AsteroidField : public FixedObject
{
public:


	/**
	 * @brief   Creates an asteroid field with n asteroids in it
	 * @author  Michael Micke, Frank Mehne
	 * @since   4.1.2015
	 */
    	AsteroidField(int n, string basePath = "");

	/**
	 * @brief   Destructor
	 * @author  Michael Micke, Frank Mehne
	 * @since   4.1.2015
	 */
	~AsteroidField();

	/**
	 * @brief   Renders all asteroids
	 * @author  Michael Micke, Frank Mehne
	 * @since   4.1.2015 
	 */
	void render();

private:
	// List of asteroids in the asteroid field
    	List<Asteroid*>* m_asteroids;

    	// Relative path to look for the asteroid model
    	string m_basePath;
};

}

#endif
