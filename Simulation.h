/*  declares a number of utility functions, some which you have to define yourself, while others are given in provided.cpp */

#ifndef _SIM_
#define _SIM_

/*
 DO NOT modify this header file OR submit this header file.
 It will automatically be included when your HW is being tested.
 You will need to define some of the functions declared here.
 */

#include <vector>

class HourMin;
class Customer;

/**
 This function returns a random variable with an exponential distribution
 having a specified mean value
 @param avg the mean value
 @return a random variable ~Exp(avg)
 */
double exp_rand(double avg);

/**
 This function returns a true/false value as to whether an event was a
 success in a Bernoulli trial
 @param p the probability of success
 @return whether there was a success
 */
bool bernoulli_rand(double p);

/**
 This function gives how many people entered at a given time over a time interval
 In the cases provided:
 (1) corresponds to one person / minute, always
 (2) corresponds to roughly one person every 4 minutes
 @param now the current time
 @param dT the time interval in minutes
 @return the number of people who came in
 */
size_t get_entries(const HourMin& now, int dT); // already defined in provided 

/**
 Function generates a random number of minutes that a customer will take
 at a checkout
 In the cases provided:
 (1) corresponds to every customer requring 60 minutes - WHAT are they buying???
 (2) generates a time according to an exponential distribution with mean of 5 minutes
 @return the number of minutes
 */
int get_duration_in_min(); // already defined in provided

/**
 This function determines how many checkouts are available at a given time
 In the cases provided:
 (1) corresponds to always having 20 checkouts available
 (2) corresponds to there always being 6, except during lunch where there are only 2
 @param now the current time
 @return the number of open checkouts
 */
size_t get_checkouts(const HourMin& now); // already defined in provided


/**
 This function adds new customers to the line
 @param now the current time
 @param dT the time interval in minutes
 @param queue the vector of current customers
 */
void enter(const HourMin& now, int dT, std::vector<Customer>& queue);

/**
 This function allows customers to complete their transactions
 @param now the current time
 @param queue the vector of current customers
 @param finished the vector of customers who are done
 */
void finish(const HourMin& now, std::vector<Customer>& queue, std::vector<Customer>& finished);

/**
 This function begins helping customers
 @param now the current time
 @param queue the vector of current customers
 */
void help(const HourMin& now, std::vector<Customer>& queue);

#endif
