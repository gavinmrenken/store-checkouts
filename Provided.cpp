#include "Simulation.h"
#include "Customer.h"

#include <cmath>

/*
DO NOT submit this file!
It will be modified and used to test your homework. It will make use of the clases/functions
you were asked to write.
*/

size_t get_entries(const HourMin& now, int dT) {

	// case (1)
	return 1; // always 1/minute

	// case (2)
	//static constexpr double p = 0.25;
	//return bernoulli_rand(p) ? 1 : 0;
}

size_t get_checkouts(const HourMin& now) {
	// case(1) 
	return 20;

	// case(2) 
	//return (now.before({ 12,0 }) || HourMin{ 13,0 }.before(now)) ? 6 : 2;
}

int get_duration_in_min() {
	// case (1)
	return 60;

	// case (2) 
	//static constexpr double avg = 5;  
	//return static_cast<int>( std::round(exp_rand(avg)));
}
