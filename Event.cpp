//
// Created by redouane on 09/09/22.
//
#include "Event.h"

/**
 * Constructor for Event class
 * @param triggerTime
 */
Event::Event(double triggerTime, DES *simPtr) {
    _time = triggerTime;
    _simPtr = simPtr;
}


Event::~Event() {}

double Event::getTime() {
    return _time;
}

void Event::handle() {}