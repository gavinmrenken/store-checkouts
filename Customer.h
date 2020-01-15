/*  Customer.h provides the definition of the Customer class. You have a choice about defining the member functions and constructor inside the class interface or defining the member functions in Definitions.cpp. */
#ifndef _CUSTOMER_
#define _CUSTOMER_

#include "HourMin.h"
#include "Simulation.h"

class Customer {        // creating class Customer

private:

	HourMin start;      // stores two member variables start, end of type HourMin
	HourMin end;
	int duration;       // int for how many minutes their checkout takes
	bool being_helped;  // bool to later tell whether customer is at a checkout being helped

public:

	Customer(HourMin _start, HourMin _end) : start(_start), end(_end), being_helped(false), duration(get_duration_in_min()) {}      // constructor intializer list for Customer (takes in member variables from private and calls upon the get_duration_in_min() function from provided.cpp

	void help(HourMin now) {            // mutator functions that ensures the customer is being helped if not already
		if (being_helped == false) {
			being_helped = true;
			now.advance_min(duration);  // advances time to now
			end = now;
		}
	}

	bool is_being_helped() const {       // accessor function that returns true if being_helped is true and false otherwise
		if (being_helped == true) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_done(HourMin now) const {    // accessor function that takes in current time represented by now and returns true if they are being helped and it is passed time - otherwise returns false
		if (being_helped == true && now.before(end) == false) {  // second half of conjunction represents the inverse of whether the current time is at or past the end of the function
			return true;
		}
		else {
			return false;
		}
	}

	int get_minutes() const {   // returns number of minutes, represented by difference, from start to end
		int difference = start.minutes_to(end); // calls the the minutes_to function given in provided.cpp
		return difference;
	}

	void print() const {     // print accessor function that prints final formatting 
		std::cout << "Arrival: " << start.as_string() << " Exit: " << end.as_string();

	}
};

#endif
