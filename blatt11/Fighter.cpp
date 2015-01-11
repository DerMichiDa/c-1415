/**
 * Fighter.cpp
 *
 */

#include "Fighter.hpp"
#include "Bullet.hpp"

#include <iterator>
#include <vector>

namespace asteroids {

void Fighter::shoot() {
	// Create a new bullet with this fighter's position and x-Axis
	Bullet* bullet = new Bullet(this->m_position, this->m_xAxis, 2);

	// Start a new thread, move the bullet
	bullet->start();

	// Add it to this fighter's vector of bullets
	m_bullets.push_back(bullet);
}

void Fighter::render() {
	// Render the fighter
	TexturedMesh::render();

	// VERSION MIT ITERATOR WILL IRGENDWIE NOCH NICHT

	// create iterator
//	std::vector<Bullet*>::iterator iter;
//
//	// move through vector using the iterator
//	for (iter = m_bullets.begin(); iter < m_bullets.end(); ++iter) {
//
//		// if bullet is not alive anymore
//		if (*iter->isAlive()) {
//
//			// erase it
//			m_bullets.erase(iter);
//		} else {
//
//			// render it otherwise
//			iter->render();
//
//		}
//	}

	for (unsigned int i = 0; i < m_bullets.size(); i++) {

		// if bullet is not alive anymore
		if (!m_bullets.at(i)->isAlive()) {

			// erase it
			m_bullets.erase(m_bullets.begin() + i);
		} else {

			// render it otherwise
			m_bullets.at(i)->render();

		}

	}

}

} // namespace asteroids

