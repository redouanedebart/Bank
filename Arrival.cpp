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
Arrival::Arrival(double triggerTime, Bank *simPtr){
    _simPtr = simPtr;
    _time = triggerTime;
}

/**
 * Copy constructor
 * @param arrival reference to an arrival object
 */
Arrival::Arrival(const Arrival &arrival) : Event(arrival) {
    _time = arrival._time;
    _simPtr = arrival._simPtr;
}

Arrival::~Arrival() = default;

/**
 * If any Cashier is available, the client goes to the first Cashier available,
 * else, the client is added to the getWaitingQueue
 * this is also responsible for the creation of other arrivals
 */
void Arrival::handle() {
    using namespace std;
    double time;
    cout<<"handling client arrival"<<endl;
    Client client(_time); //create the client
    cout<<"created the client"<<endl;
    //check if there is a free cashier to serve the client
    if(_simPtr->firstFreeCashier() == nullptr) {
        std::cout << "no free cashier for the moment, the client goes to the waiting queue" << std::endl;
        _simPtr->getWaitingQueue()->addClient(client) ;
    }else {
        cout<<"cashier available"<<endl;
        _simPtr->firstFreeCashier()->serve(client); //departure is added to event queue
    }
    //if the client is not served it means that all cashiers are serving,
    // which means that many departure are in event queue
    if (!_simPtr->getArrivalTimings().empty()){
        time = _simPtr->getArrivalTimings().front();
        auto *arr = new Arrival(time, this->_simPtr);
        _simPtr->addEvent(*arr);
        _simPtr->_arrivalTimings.pop();
    }
}

    


