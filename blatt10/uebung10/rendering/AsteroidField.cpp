#include "AsteroidField.hpp"
#include "math/Randomizer.hpp"
#include "List.tpp"

namespace asteroids
{

AsteroidField::AsteroidField(int quantity, string basePath) :
    m_basePath(basePath)
{
	float scale;
	Vertex<float> vert;

	// create List of Asteroids
	m_asteroids = new List<Asteroid*>();

 	// generate asteroids
	for(int i = 0; i < quantity; i++)
	{
		// create asteroid mesh
	    	TriangleMesh* mesh = TriangleMeshFactory::instance().getMesh(m_basePath + "asteroid.3ds");

		// get position of the asteroid
        	vert = Randomizer::instance()->getRandomVertex(5000);

		// get scale of the asteroid
		scale = Randomizer::instance()->getRandomNumber(1, 5);
        	m_asteroids->insert(new Asteroid(mesh, vert, scale));
	}

}


void render_asteroid(Asteroid* a)
{
	// call render function of asteroid
	a->render();
}


void AsteroidField::render()
{
	// render all asteroids in the listy
	m_asteroids->for_each(render_asteroid);
}


}
