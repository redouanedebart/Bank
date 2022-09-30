//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "../include/Departure.h"

//--------Class Implementation--------//
 /**
  * Constructor for the class Departure
  * @param c the client concerned by this Event
  * @param cash the cashier concerned
  * @param time trigger time of the event
  * NOTE: Both the parameters are pointers
  */
Departure::Departure(Client* c, Cashier* cash, double time){
    _clientPtr = c;
    _cashierPtr = cash;
    _time = time;
}

/**
 * If the waitingQueue is empty, the cashier waits, else he serves the next client
 * the waitingQueue is accessed via the pointer on bank in the cashier class
 */
void Departure::handle() {
    if (_cashierPtr->getBank()->getWaitingQueue()->isEmpty()) {
        _cashierPtr->wait();
    } else {
        _cashierPtr->serve(*(_cashierPtr->getBank()->getWaitingQueue()->remove()));
    }
}

Departure::~Departure() = default;