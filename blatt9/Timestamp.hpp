/**
 * @brief A helper class for automated time stamping. Timing is
 * 		  started as soon as an object of this class is created.
 * 		  To time some parts of a program, just create a new object
 * 		  and use the provided output operator to display the elapsed
 * 		  time.
 */

#ifndef TIMESTAMP_HPP_
#define TIMESTAMP_HPP_

namespace asteroids {

class Timestamp {

public:
	/**
	 * @brief	Constructor.
	 */
	Timestamp();

	/**
	 * @brief	Returns the current system time in milliseconds
	 */
	unsigned long getCurrentTimeInMs() const;

	/**
	 * @brief 	Returns the milliseconds since object creation
	 */
	unsigned long getElapsedTimeInMs() const;

	/**
	 * @brief	Returns the current system time in seconds
	 */
	double getCurrentTimeinS() const;

	/**
	 * @brief	Returns the time since instantiation in seconds
	 */
	double getElapsedTimeInS() const;

	/**
	 * @brief	Resets the internal timer
	 */
	void resetTimer();

	/**
	 * @brief Returns a string representation of the current timer value
	 *
	 */
	std::string getElapsedTime() const;

	/**
	 * @brief Destructor
	 */
	virtual ~Timestamp();

private:
	/// The system time at object instantiation
	unsigned long m_startTime;
};

} /* namespace asteroids */


#endif /* TIMESTAMP_H_ */
