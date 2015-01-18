/*
 * PathPlanner.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: tank
 */

#include "PathPlanner.hpp"
#include <boost/filesystem.hpp>
#include "boost/filesystem/fstream.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>
#include <string>
#include <boost/property_map/property_map.hpp>
#include "../math/Vertex.hpp"

using namespace std;

namespace asteroids {

PathPlanner::PathPlanner(std::string mapfile) {

	// get the path for a filesystem
	filesystem::path mapFileName(mapfile);

	// create stream for reading file
	filesystem::ifstream inStream(mapFileName);

	// read the number of vertices
	string line;
	int numVertices;

	// get first line of the file
	getline(inStream, line);

	// get number of vertices
	istringstream inStringStream(line);
	inStringStream >> numVertices;

	// Create the Graph
	m_graph = Graph(numVertices);

	// define new types for easier handling later (see Kevin Bacon example)
	// Map of the names of the stars
	typedef property_map<Graph, vertex_name_t>::type nameMap;
	nameMap starNames = get(vertex_name, m_graph);

	// map of the edge weights/distances
	typedef property_map<Graph, edge_weight_t>::type distanceMap;
	distanceMap starDistances = get(edge_weight, m_graph);

	typedef graph_traits<Graph>::vertex_descriptor Vertex;

	typedef map<string, Vertex> NameVertexMap;
	NameVertexMap stars;

	// read all the vertices from the file
	m_starCoordinates = vector<Vertex<float>> > (numVertices);

	for (int i = 0; i < numVertices; i++) {

		// storage for the name and coordinates of each read star
		string starName;
		float coordX;
		float coordY;
		float coordZ;

		// read current line
		getline(inStream, line);
		inStringStream(line);

		// get the name and the coordinates for each star
		inStringStream >> starName;
		inStringStream >> coordX >> coordY >> coordZ;

		// store the read information in the maps
		starNames[i] = starName;							// name of star

		Vertex<float> tmpVertex(coordX, coordY, coordZ);
		m_starCoordinates[i] = tmpVertex;				// coordinates of star

		m_nameIdxMap[starName] = i;							// index of star

	}

	// read all the edges from the file
	while (getline(inStream, line)) {

		int startIdx, endIdx;
		inStringStream(line);

		inStringStream >> startIdx >> endIdx;

		// calculate the distance of the two vertices defining the current edge
		float distance = m_starCoordinates[startIdx].dist(
				m_starCoordinates[endIdx]);

		// save the distance as a edge weight in the graph
		graph_traits<Graph>::edge_descriptor e;
		bool inserted;

		// add athe new edge to the graph
		boost::tie(e, inserted) = add_edge(startIdx, endIdx, m_graph);
		if (inserted) {
			starDistances[e] = distance;
		}

	}
}

PathPlanner::~PathPlanner() {
	// TODO Auto-generated destructor stub
}

} /* namespace asteroids */
