/**
 * @file TriangleMeshFactory.cpp
 * 
 * @author Frank Mehne
 * @author Michael Micke
 */

 #include "TriangleMeshFactory.hpp"
 #include "ReadPLY.hpp"
 #include "Read3DS.hpp"

static TriangleMeshFactory* TriangleMeshFactory::instance()
{
    if(singleton == 0) singleton = new TriangleMeshFactory();
    return singleton;
}

TriangleMesh* TriangleMeshFactory::getMesh (const string &filename)
{
    MeshReader reader = 0;
    TriangleMesh* mesh = 0;
    // Dateiendung ermitteln
    if( filename.compare(filename.size() - 4, 4, ".ply") )
    {
        // lade PLY-Data
        reader = new ReadPLY(filename);
    }
    else if (filename.compare(filename.size() - 4, 4, ".3ds") )
    {
        // lade 3ds-Data
        reader = new Read3DS(filename);
    }

    mesh = reader.getMesh();

    // free memory
    delete reader;

    return mesh;
}
