/*
 * Logger.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Michael Micke, Frank Mehne
 */

#include "Logger.hpp"
#include "Timestamp.hpp"
#include <fstream>


using namespace std;

namespace asteroids {

Logger::Logger(Timestamp& timestamp) {

	// set default output to console
	m_destinationFlag = false;
	m_outputStream = cout;

	// save reference to Timestamp instance
	m_timestampRef = timestamp;

}

Logger::~Logger() {

	// close the stream
	if(m_destinationFlag == true){

	}

}

void Logger::setOutputToStdout() {

	// set the output to the console
	m_destinationFlag = false;
	m_outputStream = cout;
}

void Logger::setOutputFile(string filename) {

	// set the output stream to the file
	m_destinationFlag = true;

	// create output stream
	ofstream stream(filename, ios_base::app);
	m_outputStream = stream;

	// check if stream creation was successful
	if (m_outputStream.fail()) {
		cout
				<< "ERROR: Could not open output file for logger!\nOutput is presented on console..."
				<< endl;

		// set the output to the console
		setOutputToStdout();
	}
}

void Logger::operator<<(Logger& logger, string event) const {

	// check where to output
	if (m_destinationFlag == false) {

		// output on console
		cout << m_timestampRef << " - " << event << endl;
	} else {

		// write to file
		m_outputStream << m_timestampRef << " - " << event << endl;
	}

}

} /* namespace asteroids */
