//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "DES.h"
#include "Event.h"
//--------Class Implementation--------//

using namespace std;

/**
 * Method that returns the time for other classes
 *
 * @return the current time in the simulation
 */
double DES::getTime() {
    _stopTime = clock();
    _diffTime = _startTime - _stopTime;
    return _diffTime;
}

/**
 * starts the clock and generate the schedule for the events
 * using random generators. It is also destroying the events once they are finished
 */
void DES::run() {
    _startTime = clock();
    //TODO: Take care of events destruction
    while(!_evtQueue.empty()){
        _evtQueue.front()->handle();
        _evtQueue.pop();
    }
    _diffTime = getTime();
}

/**
 * Adds an Event to the event list ?
 * @param e is an Event (arrival or departure)
 */
void DES::addEvent(Event e) {
    _evtQueue.push(&e);
}

/**
 * generate random number in between 70% and 130% of the entry value
 * this will be used to generate effective service duration of cashiers
 * @param value mean service duration of cashiers
 * @return effective duration (between 70% and 130% of value)
 */
double DES::generateEffectiveServiceTime(double value) {
    double higherBound = value * 1.3;
    double lowerBound = value * 0.7;
    srand(time(nullptr));
    double randomNumber;
    randomNumber = (double)rand() / higherBound;
    return lowerBound + randomNumber *(higherBound - lowerBound);
}

/**
 * Generating timings of Events using a poisson process,
 * events are then created in this function and stored in event queue field
 *
 * @param meanTimeBetweenArrival the mean time between arrivals
 *
 * The number of arrivals in non-overlapping intervals are statistically independent.
 * The probability of two or more arrivals happening during t is negligible compared
 * to the probability of zero or one arrival, i.e., it is of the order o( t).
 */
void DES::generateTimings(double meanTimeBetweenArrival, double expectedDur) {
    std::random_device rd; // uniformly-distributed integer random number generator to seed
                           //the next line
    std::mt19937 rng (rd ()); // mt19937: Pseudo-random number generation

    double lambda = 1 / meanTimeBetweenArrival;
    std::exponential_distribution<double> exp (lambda);

    double sumArrivalTimes=0;
    double newArrivalTime;

    while(sumArrivalTimes<=expectedDur)
    {
        newArrivalTime=  exp.operator() (rng);// generates the next random number in the distribution
        sumArrivalTimes  += newArrivalTime;
        //TODO: create events and add them to the queue
    }
}

DES::~DES() = default;
