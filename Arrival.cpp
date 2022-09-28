//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "Arrival.h"
#include <iostream>

//--------Class Implementation--------//

/**
 *
 * @param triggerTime to know when the event happens
 * @param simPtr points to bank so we can access the cashiers
 */
Arrival::Arrival(double triggerTime, Bank *simPtr): Event(){
    _time = triggerTime;
    _simPtr = simPtr;
}

/**
 * Copy constructor
 * @param arrival reference to an arrival object
 */
Arrival::Arrival(Arrival &arrival){
    _time = arrival._time;
}

Arrival::~Arrival() {}

/**
 * If any Cashier is available, the client goes to the first Cashier available,
 * else, the client is added to the getWaitingQueue
 * this is also responsible for the creation of other arrivals
 */
void Arrival::handle() {
    double time;

    Client client(_time); //create the client

    //check if there is a free cashier to serve the client
    if(_simPtr->firstFreeCashier() == nullptr) {
        std::cout << "no free cashier for the moment, the client goes to the waiting queue" << std::endl;
        _simPtr->getWaitingQueue()->addClient(client) ;
    }else {
        _simPtr->firstFreeCashier()->serve(client); //departure is added to event queue
    }
    //if the client is not served it means that all cashiers are serving,
    // which means that many departure are in evtqueue
    time = _simPtr->getArrivalTimings().front();
    Arrival arr(time, _simPtr);
    _simPtr->addEvent(arr);
    _simPtr->getArrivalTimings().pop();
}

    


