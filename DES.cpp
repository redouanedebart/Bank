//
// Created by redouane on 09/09/22.
//

#include "DES.h"

using namespace std;
// lambda = 1/meanTimeBetweenArrival
DES::~DES() {}

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
 * starts the clock
 */
void DES::run() {
    _startTime = clock();
    //TODO: simulate the time between clients arrival:
    // use an exponential distribution to get a poisson process
    //addEvent(e) according to timings obtained, while triggerTime <= expected duration
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
    srand(time(0));
    double randomNumber;
    randomNumber = (double)rand() / higherBound;
    return lowerBound + randomNumber *(higherBound - lowerBound);
}

/**
 * Generating timings of Events using a poisson process,
 * events are then created and stored in event queue field
 */
void DES::generateTimings() {

}