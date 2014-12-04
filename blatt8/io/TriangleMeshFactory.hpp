/**
 * @file TriangleMeshFactory.hpp
 * 
 * @author Frank Mehne
 * @author Michael Micke
 */

#ifndef TRIANGLEMESHFACTORY_HPP_
#define TRIANGLEMESHFACTORY_HPP_

namespace
{

class TriangleMeshFactory
{
    static TriangleMeshFactory singleton;
    TriangleMeshFactory();
public:
    static TriangleMeshFactory instance();
    TriangleMesh* getMesh (const string &filename);
}

}

#endif
