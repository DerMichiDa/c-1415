/*
 * PathPlanner.hpp
 *
 *  Created on: Jan 18, 2015
 *      Author: Michael Micke, Frank Mehne
 */

#ifndef PATHPLANNER_HPP_
#define PATHPLANNER_HPP_

#include <list>
#include <string>
#include <map>
#include <vector>
#include "math/Vertex.hpp"
#include <boost/graph/adjacency_list.hpp>

using namespace boost;

namespace asteroids {

class PathPlanner {
public:

	// Typendefinition eines Graphen
	typedef adjacency_list<vecS, vecS, undirectedS,
			property<vertex_name_t, std::string>, property<edge_weight_t, float> > Graph;

	/**
	 * @brief Constructor, that reads a Graph from the given file
	 *
	 * @param mapfile The path to the file defining the Graph
	 */
	PathPlanner(std::string mapfile);

	/**
	 * @brief Returns the shortest path, that leads from 'position' to 's' and then to 'e'
	 */
	std::list<Vertex<float> > getPath(Vertex<float> position, std::string s,
			std::string e);

	virtual ~PathPlanner();

private:
	Graph m_graph;										// The graph

	std::map<std::string, int> m_nameIdxMap;			// Map of the indices of each star by name
	std::vector<Vertex<float> > m_starCoordinates;		// Vector of the coordinates of each star

};

} /* namespace asteroids */

#endif /* PATHPLANNER_HPP_ */
