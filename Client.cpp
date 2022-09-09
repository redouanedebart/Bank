//
// Created by redouane on 09/09/22.
//
#include "Client.h"

Client::Client(double arrivalTime) {
    _time = arrivalTime;
}

Client::~Client() {}

/**
 * Accessor for the _time field
 * @return _time which is the time of arrival of the Client
 */
double Client::arrivalTime() {
    return _time;
}