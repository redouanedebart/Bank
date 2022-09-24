//
// Created by redouane on 09/09/22.
//

#include "DES.h"

using namespace std;
//idea to simulate the time between clients arrival: use an exponential distribution to get a poisson process
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
}

/**
 * Adds an Event to the event list ?
 * @param e is an Event (arrival or departure)
 */
void DES::addEvent(Event e) {
    _evtList.push_back(e);
}