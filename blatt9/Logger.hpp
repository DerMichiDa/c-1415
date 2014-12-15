/*
 * Logger.hpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Michael Micke, Frank Mehne
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <string>
#include "Timestamp.hpp"

using namespace std;

namespace asteroids {

class Logger {
public:
	virtual ~Logger();

	/**
	 * @brief	Sets the path to the file in which the logging output is written.
	 * 			All logging events will be written to this file instead of the console
	 *
	 * @param 	filename	The path of the output file
	 * @author 	Michael Micke
	 * @author	Frank Mehne
	 * @since	14.12.2014
	 */
	void setOutputFile(string filename);

	/**
	 * @brief	Changes output destination to the console.
	 * 			Future logger events will be printed there
	 *
	 * @author 	Michael Micke
	 * @author	Frank Mehne
	 * @since	14.12.2014
	 */
	void setOutputToStdout();

	/**
	 * @brief Operator for putting out a timestamped event
	 *
	 * @param logger	The logger which specifies the output destination
	 * @param event		The desired output as a string
	 *
	 * @author	Michael Micke
	 * @author	Frank Mehne
	 *
	 * @since 14.12.2014
	 */
	void operator<<(Logger& logger, string event) const;

    /** 
     * @brief Getter for singleton
     */
    static Logger getInstance();
    /**
     * @brief clean storage
     */
    static void deleteSingleton();

private:
	/**
	 * Determines whether logger events are written in file or to the console
	 * True 	=> output in file
	 * False	=> output on console (default)
	 */
	bool m_destinationFlag;

	/**
	 * Reference to the global Timestamp instance for getting times
	 */
	Timestamp& m_timestampRef;

	/**
	 * The stream in which the logger events are written
	 */
	ostream m_outputStream;
    /**
     * hide constructor
     */
	Logger();

    static singleton;
};

} /* namespace asteroids */

#endif /* LOGGER_HPP_ */
