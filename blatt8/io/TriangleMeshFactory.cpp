/**
 * @file TriangleMeshFactory.cpp
 * 
 * @author Frank Mehne
 * @author Michael Micke
 */

static TriangleMeshFactory* TriangleMeshFactory::instance()
{
    if(singleton == 0) singleton = new TriangleMeshFactory();
    return singleton;
}

TriangleMesh* TriangleMeshFactory::getMesh (const string &filename)
{
    
}
