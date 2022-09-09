//
// Created by redouane on 09/09/22.
//
#include "Arrival.h"

Arrival::Arrival() {} //TODO: check implementation of derived classes in poste project,
                    //for this class and departure class

/**
 * Copy constructor
 * @param arrival reference to an arrival object
 */
Arrival::Arrival(Arrival &arrival) {
    _time = arrival._time;
}

Arrival::~Arrival() {}

/**
 * If any Cashier is available, the client goes to the first Cashier available,
 * else, the client is added to the queue
 */
void Arrival::handle() {}