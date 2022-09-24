//
// Created by redouane on 09/09/22.
//

#include "DES.h"

using namespace std;

DES::~DES() {}

/**
 * Method that returns the time for other classes
 *
 * @return the current time in the simulation
 */
double DES::getTime() {//TODO: finish this method ( clock for the sim)
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
void DES::addEvent(Event e) {}