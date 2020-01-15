/*  Gives a main routine and implements the logic of customers coming in/out, and printing the statistics (this file might be modified when your homeworks are being tested) */

#include "HourMin.h"
#include "Customer.h"
#include "Simulation.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

/*
 DO NOT submit this Source.cpp. It will be modified and used to test
 your homework.
 It makes use of the functionalities in HourMin.h, Customer.h, and Simulation.h
 */

int main() {

	std::srand(std::time(nullptr));

	// case (1) - just for debugging/sanity checking
	const HourMin day_start(8, 0), day_end(8, 40);

	// case(2) - 9am - 5pm day
	//const HourMin day_start(8, 0), day_end(17, 0);

	const int dT_min = 1;

	std::vector<Customer> customers; // to store customers still in line
	std::vector<Customer> finished; // to store customers who are done

	HourMin now = day_start;


	// while the end of day has not been reached or
	// while there are customers to help, we keep going
	while (now.before(day_end) || !customers.empty()) {

		// people enter
		if (now.before(day_end)) { // can still come in if before closing
			enter(now, dT_min, customers);
		}

		// people may leave
		finish(now, customers, finished);

		// and they may be helped
		help(now, customers);

		// advance the time
		now.advance_min(dT_min);
	}

	// store average number of minutes
	double avg_min = 0;

	for (const auto& c : finished) { // look at every finished customer
		avg_min += c.get_minutes();
	}
	avg_min /= finished.size(); // divide by size to make it an average

	std::cout << "Today there were " << finished.size() << " customers. They spent on average " <<
		avg_min << " minutes in the store. Their arrivals/exits were: " << '\n';

	for (const auto& c : finished) { // print enter/exit for all finished cusomters
		c.print();
		std::cout << '\n';
	}

	std::cin.get();

	return 0;
}
