/*
 * main.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: tank
 */

#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

struct accumulator: public std::unary_function<int, void> {

	// internal state
	int sum;

	// Constructor
	accumulator() {
		sum = 0;
	}

	// overloading operator()
	void operator()(int number) {

		// summing up values
		sum += number;
	}
};

int main() {

	// create vector
	std::vector<int> vector;

	// fill vector with 10 ones
	for (int i = 0; i < 10; i++) {

		vector.push_back(1);
	}

	// create accumulator
	accumulator sum = for_each(vector.begin(), vector.end(), accumulator());


	// print result to console
	std::cout << "The sum is: " << sum.sum << std::endl;

}
