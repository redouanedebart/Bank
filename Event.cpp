//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "Event.h"

//--------Class Implementation--------//

/**
 * Constructor for Event class
 * @param triggerTime
 */
Event::Event(double triggerTime, DES *simPtr) {
    _time = triggerTime;
    _simPtr = simPtr;
}

/**
 * Accessor to the _time field
 * @return the trigger time of the Event
 */
double Event::getTime() {
    return _time;
}

/**
 * virtual method redefined in each subclasses
 */
void Event::handle() {}

Event::~Event() = default;

