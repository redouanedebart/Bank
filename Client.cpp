//
// Created by redouane on 09/09/22.
//
#include "Client.h"

Client::Client(double arrivalTime) {
    _time = arrivalTime;
}

Client::~Client() {}

double Client::arrivalTime() {
    return _time;
}