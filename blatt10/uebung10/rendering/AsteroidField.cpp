#include "AsteroidField.hpp"
#include "math/Randomizer.hpp"

namespace asteroids
{


AsteroidField::AsteroidField(int quantity, string basePath) :
    m_basePath(basePath)
{
	float scale;
	Vertex<float> vert;
	Asteroid asteroid;

	m_asteroids = new List<Asteroid>();
 	// Generate asteroids
	for(int i = 0; i < quantity; i++)
	{
	    TriangleMesh* mesh = TriangleMeshFactory::instance().getMesh(m_basePath + "asteroid.3ds");

        vert = Randomizer::instance()->getRandomVertex(500);
        scale = Randomizer::instance()->getRandomNumber(1, 5);
        asteroid = new Asteroid(mesh, vert, scale);
        m_asteroids->insert(asteroid);
	}

}

AsteroidField::~AsteroidField()
{
    delete m_asteroids;
}


void AsteroidField::render()
{
	m_asteroids->for_each(render_asteroid);
}

void AsteroidField::render_asteroid(Asteroid a)
{
	a.render();
}

}
