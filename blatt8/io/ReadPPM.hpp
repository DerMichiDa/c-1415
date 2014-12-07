/*
 * ReadPPM.hpp
 *
 *@brief	This class is for reading pictures from the .ppm format (binary and in ASCII)
 *
 *  Created on: Dec 6, 2014
 *      Author: Michael Micke, Frank Mehne
 */

#ifndef READPPM_HPP_
#define READPPM_HPP_

#include <fstream>
#include <iostream>

using namespace std;

namespace asteroids {

class ReadPPM: BitmapReader {
public:

	/**
	 * @brief Constructor with a file to read
	 *
	 * @author	Michael Micke, Frank Mehne
	 * @since 7.12.2014
	 */
	ReadPPM(const char* filename);
	virtual ~ReadPPM();

private:

	/**
	 * @brief 	Loads and reads a file
	 *
	 * @return 	1 if successful, 0 if not
	 *
	 * @author	Michael Micke, Frank Mehne
	 * @since 7.12.2014
	 */
	int loadFile(const char* filename);

	/**
	 * @brief	Reads a line from the stream but only if it
	 * 			does not start with the char defined in 'selector'
	 *
	 * @param	inStream	A reference to the incoming stream
	 * @param 	line		Where the read line is written to
	 * @param 	selector	A char to determine which lines schould not be read
	 *
	 * @author	Michael Micke, Frank Mehne
	 * @since 	7.12.2014
	 */
	void readSelectively(ifstream& inStream, string& line, string selector);

};

} /* namespace asteroids */

#endif /* READPPM_HPP_ */
