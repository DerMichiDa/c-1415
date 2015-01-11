/**
 * Bullet.cpp
 *
 */

#include "Bullet.hpp"

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <unistd.h>
#include <thread>
#include <chrono>

#include "../math/Vertex.hpp"

namespace asteroids {

Bullet::Bullet(Vertex<float> fighter_position, Vertex<float> fighterAxis,
		float bulletSpeed) {

	m_fighter_position = fighter_position;

	// axis has to be inverted otherwise the bullets come out of the rear end of the fighter
	m_fighterAxis = fighterAxis * (-1);

	m_bulletSpeed = bulletSpeed;
	m_alive = true;
}

Bullet::~Bullet() {

}

bool Bullet::isAlive() {

	// return whether the bullet is still alive
	return m_alive;
}

void Bullet::stop() {

	// wait for the bullet thread to stop
	runThread.join();

	// The bullet finished/ is not alive anymore
	m_alive = false;
}

void Bullet::start() {

	// Start a new thread calling the run()-function
	this->runThread = std::thread(&Bullet::run, this);

}

void Bullet::run() {

	// make chrono event of 1000 microseconds
	std::chrono::microseconds sleepTime(1000);

	// Let the Bullet move one moving-unit at each timestep
	for (int i = 0; i < m_lifetime; i++) {

		// determine new position of bullet
		m_position += m_fighterAxis * m_bulletSpeed;

		// let the thread sleep
		std::this_thread::sleep_for(sleepTime);
	}

	// The bullet finished/ is not alive anymore
	m_alive = false;
}

void Bullet::render() {
	// Compute transformation matrix
	computeMatrix();
	// Push old transformation of the OpenGL matrix stack and
	// start rendering the bullet in according to the
	// internal transformation matrix
	glPushMatrix();
	glMultMatrixf(m_transformation);
	glutSolidSphere(10, 16, 16);
	// Pop transformation matrix of this object
	// to restore the previous state of the OpenGL
	// matrix stack
	glPopMatrix();
}

} // namespace asreroids

