/*  Simulation.cpp should provide the definitions for the enter, exp rand, bernoulli rand, finish, and help functions. */

#include "Simulation.h"
#include "Customer.h"
#include "HourMin.h"

#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>

double exp_rand(double avg) // function returns a random variable with an exponential distribution having a specified mean value
{ 
	double U = rand() / (RAND_MAX + 1.0);       // generating an exponential random variable U uniformly distributed on [0,1)
	double exponential_random = (-avg) * log(1 - U);      // given calculation in spec
	return exponential_random;
}

bool bernoulli_rand(double p)  // function returns a true/false value as to whether an event was a success in a Bernoulli trial
{ 
	double rand_num = rand() / (RAND_MAX + 1.0); ; // generating random number between [0,1)
	if (rand_num < p) {      // in the event of a success
		return true;
	}
	else {                // in the event of a failure 
		return false;
	}
}

void enter(const HourMin& now, int dT, std::vector<Customer>& queue) // function adds new  customers to the line 
{
	size_t number_customers = get_entries(now, dT);		// use get_entries function from provided.cpp to see how many people have entered at a given time over a time interval
	for (size_t i = 0; i < number_customers; ++i) {		// iterates throughthe number of customers 
		HourMin time = now;
		Customer current_customer(time, time);		// creates object for entering customers 
		queue.push_back(current_customer);			// adds the new customer to the line 
	}
}

void finish(const HourMin & now, std::vector<Customer> & queue, std::vector<Customer> & finished) //  function allows customers to complete their transactions
{
	for (int i = 0; i < queue.size(); ) {	// iterates through the line without incrementing 
		if (queue[i].is_done(now)) {		// if the customer is done... 
			finished.push_back(queue[i]);	// add to vec finished 
			queue.erase(queue.begin() + i);	// remove customer 
			++i;							// increment so it moves to next customer 
		}
		else if (queue[i].is_done(now) == false) {	// if not done moves to next customer to make sure it doesnt skip over any values 
			++i;
		}
	}
}

void help(const HourMin & now, std::vector<Customer> & queue) // function begins helping customers
{
	size_t free_registers = get_checkouts(now);		// use get_checkouts function (determines how many checkouts are available at a given time) from provided.cpp to see the amount of free registers 
	size_t num_waiting = 0;	
	if (free_registers < queue.size()) {			// for when the size of the line is greater than the number of free registers 
		num_waiting = free_registers;
	}
	else {
		num_waiting = queue.size();					// sets the amount of customers equal to the size of the line 
	}
	for (size_t i = 0; i < num_waiting; i++) {		// increments through the line of customers 
		if (queue[i].is_being_helped() == false) {  // makes sure that the customers will now be helped 
			queue[i].help(now);
		}
	}
}
