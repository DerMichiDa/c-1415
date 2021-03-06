/**
 * @file
 * Bullet.hpp
 *
 */

#ifndef BULLET_HPP_
#define BULLET_HPP_

#include "TriangleMesh.hpp"

#include <GL/glu.h>
#include <GL/glut.h>

#include <thread>
#include <chrono>

namespace asteroids {

/**
 * @brief Renders a Bullet
 */
class Bullet: public TriangleMesh {

public:

	/**
	 * @brief Contructor. Build a bullet on the given Fighter's
	 *                      position. The bullet will move on the
	 *                      given axis.
	 * @param   fighter_position   Position of the fighter that shoots this bullet
	 * @param   fighter_axis   Axis the bullet will move on
	 */
	Bullet(Vertex<float> fighter_position, Vertex<float> fighterAxis,
			float bulletSpeed);

	~Bullet();

	/**
	 * @brief Starts bullet movement
	 */
	void start();

	/*
	 * @brief Stops bullet movement
	 */
	void stop();

	/**
	 * @brief Renders the bullet via glutSolidSphere.
	 */
	void render();

	/**
	 * @brief Returns the status of this bullet.
	 * @return false, if the bullet's lifetime is over and true otherwise
	 */
	bool isAlive();

private:

	/**
	 * @brief Moves the bullet until it's lifetime is over.
	 */
	void run();

	// Lifetime, i.e., how many timesteps the bullet visible
	static const int m_lifetime = 9000;

	// True, if the bullet's lifetime isn't over yet
	bool m_alive;

	// Flight direction of the bullet
	Vertex<float> m_fighterAxis;

	// The fighters position
	Vertex<float> m_fighter_position;

	// Movement speed of the Bullet
	float m_bulletSpeed;

	// thread for bullet movement
	std::thread runThread;

	/// TODO: ADD TIMING AND THREAD FUNCTIONALITY
};

} // namespace asteroids

#endif /* BULLET_HPP_ */
