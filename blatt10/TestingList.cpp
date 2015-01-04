/*
 * ListTest.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: Michael Micke, Frank Mehne
 */

#include "List.tpp"
#include <iostream>

using namespace std;

/**
 * @brief Prints the given Integer 'data' to the console
 *
 * @param data The Integer that has to be printed
 *
 * @author Michael Micke
 * @author Frank Mehne
 *
 * @since 2.1.2015
 */
void printData(int data) {

	// print out 'data' to the console
	cout << data << endl;
}



int main(int argc, char** argv) {

	// Create a new List of Integers
	List<int>* list = new List<int>();

	// Push Integers in the list
	for (int i = 0; i < 10; i++) {
		list->insert(i);
	}

	// print all the elements of the list
	list->for_each(printData);
}
