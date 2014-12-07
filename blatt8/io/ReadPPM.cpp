/*
 * ReadPPM.cpp
 *
 *  Created on: Dec 6, 2014
 *      Author: tank
 */

#include "ReadPPM.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

namespace asteroids {

ReadPPM::ReadPPM(const char* filename) {

	// set member variables to zero
	m_height = 0;
	m_width = 0;
	m_pixels = 0;

	// load and read the file
	loadFile(filename);

}

ReadPPM::~ReadPPM() {
}

void ReadPPM::readSelectively(ifstream& inStream, string& line,
		string selector) {

	// read the first line
	getline(inStream, line);

	// read further lines if the dont start with 'selector'
	while (inStream.is_open() && line.compare(0, 1, selector)) {

		getline(inStream, line);
	}
}

int ReadPPM::loadFile(const char* filename) {

	// try to open the file
	ifstream fileStream;
	fileStream.open(filename);

	// if file could be opened
	if (fileStream.good()) {

		string currentLine;
		string selector = "#";

		// read the first line to determine the type of ppm-file
		readSelectively(fileStream, currentLine, selector);

		switch (currentLine.substr(0, 2)) {
		case "P3":

			// read the next line (width and height information)
			readSelectively(fileStream, currentLine, selector);

			// if color information is stored next to width and height
			if (count(currentLine.begin(), currentLine.end(), ' ') == 2) {

				// read the width and height of the image
				int posFirst = currentLine.find_first_of(" ");
				int posLast = currentLine.find_last_of(" ");

				m_width = atoi(currentLine.substr(0, posFirst - 1).c_str());
				m_height = atoi(
						currentLine.substr(posFirst + 1, posLast - 1).c_str());
			}
			if (count(currentLine.begin(), currentLine.end(), ' ') == 1) {

				// read the width and height of the image
				int posFirst = currentLine.find_first_of(" ");

				m_width = atoi(currentLine.substr(0, posFirst - 1).c_str());
				m_height = atoi(currentLine.substr(posFirst + 1).c_str());

				// read next line (where color info is stored)
				readSelectively(fileStream, currentLine, selector);
			}

			// allocate memory for the pixel data
			int numPixelInfo = m_width * m_height * 3;
			m_pixels = new unsigned char[numPixelInfo];

			// read the pixels from the file
			for(int i=0; i<numPixelInfo; i++){

				// read the next line
				readSelectively(fileStream, currentLine, selector);

				// get the information
				m_pixels[i] = (unsigned char) atoi(currentLine.c_str());
			}

			return 1;

			break;
		default:

			// print error message
			cerr << "ERROR: not a known format" << endl;
			break;
		}

	} else {

		// print error message
		cerr << "ERROR: Could not open the file" << endl;
	}

	// if this code is reached, something went wrong!
	return 0;
}

}
/* namespace asteroids */
