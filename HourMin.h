/*  HourMin.h provides the definition of the HourMin class. You have a choice about defining the member functions and constructor inside the class interface or defining the member functions in Definitions.cpp. */
#ifndef _HOUR_
#define _HOUR_

#include <string>
#include <iostream>

class HourMin {             // creating class HourMin
private:

	int hour, min;          // declaring member variables that represent hour and min of day

	void format() {          // private mutator function that fomats the HourMin object
		while (min >= 60) {  // increments hour and returns appropriate minute value till the function is correct
			hour++;
			min = min - 60;
		}
	}

public:

	HourMin(int _hour, int _min) : hour(_hour), min(_min) {} // constructor initializer for variabels hour, min

	void advance_min(int mins) {     // public mutator function that accepts an int for how many mins go by
		min = min + mins;           // updates minute value
		this->format();             // 'this' is being used to retrieve the time from format()
	}

	bool before(const HourMin& other) const {       // accessor function that makes sure time is not over
		int totalMins = ((hour * 60) + min);         // local variables created to be able to compare the two values
		int otherMins = ((other.hour * 60) + other.min);
		if (totalMins < otherMins) {
			return true;
		}
		else {
			return false;
		}
	}

	int minutes_to(const HourMin& other) const {    // accessor function that returns the number of mins from other
		int totalMins = ((hour * 60) + min);         // creating local variables to be able to compare the two values
		int otherMins = ((other.hour * 60) + other.min);
		int difference = otherMins - totalMins;     // subtracting the two values to find the difference
		return difference;
	}

	std::string as_string() const {     // accessor function that returns string representation of HourMin object
		std::string returnString = std::to_string(hour) + ":" + std::to_string(min);
		return returnString;
	}

};

#endif
