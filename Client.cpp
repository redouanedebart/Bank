//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "Client.h"


//--------Class Implementation--------//
/**
 * Constructor for the Client class
 * @param arrivalTime
 */
Client::Client(double arrivalTime) {
    _time = arrivalTime;
}

/**
 * Accessor for the _time field
 * @return _time which is the time of arrival of the Client
 */
double Client::arrivalTime() const {
    return _time;
}

Client::~Client() = default;