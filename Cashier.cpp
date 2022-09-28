//
// Created by redouane on 08/09/22.
//
//--------Header files included----//
#include "Cashier.h"
#include "Departure.h"
//--------Class Implementation--------//

/**
 * Cashier constructor. Will be called by Bank constructor
 * @param meanServiceDuration it is a param since it should be different for every cashier
 * @param bankPtr pointer on the bank, so we can access some infos such as actual duration
 * of the simulation
 * Creates a cashier with a given mean service time.
 */
Cashier::Cashier(double meanServiceDuration, Bank *bankPtr): _bank(bankPtr) {
    _serviceDuration = meanServiceDuration;
    _free = true;
    _clientCounter = 0;
    _actualWorkTime = 0;
}
/**
 * Copy constructor
 * @param c
 */
Cashier::Cashier(const Cashier &c) {
    _serviceDuration = c._serviceDuration;
    _clientCounter = c._clientCounter;
    _free = c._free;
    _bank = c._bank;
    _actualWorkTime = c._actualWorkTime;
}

/**
 * Accessor to the _clientCounter field.
 * @return the number of client served so far by this cashier.
 */
int Cashier::clientCount() {
    return _clientCounter;
}

/**
 * Accessor to the _free field
 * @return true if the cashier is available to serve a client
 */
bool Cashier::isFree() {
    return _free;
}

/**
 * Accessor to the _serviceDuration field
 * @return mean service duration of this cashier
 */
double Cashier::meanServiceTime() {
    return _serviceDuration;
}

/**
 * Function that computes the occupation rate of this cashier
 * @return returns a double between 0 and 1 representing the percentage
 * of occupation of this cashier.
 */
double Cashier::occupationRate() {
    return _actualWorkTime / _bank->actualDuration();
}

/**
 * Makes the client leave the queue to be served by the cashier
 * @param client
 */
void Cashier::serve(Client client) {
    double time;
    double workTime;
    _clientCounter ++;
    _free = false;
    time = _bank->getTime();//TODO: check this, there might be a problem: how does time evolves in the program ?
    workTime = _bank->generateEffectiveServiceTime(_serviceDuration);
    time += workTime;
    Departure departure(&client, this, time);
    _bank->addEvent(departure);
    _actualWorkTime += workTime;
}

/**
 * if there is no one to serve,
 *the cashier waits until there is a client to serve
 */
void Cashier::wait() {
    _free = true;
}

/**
 * Accessor to the _bank field
 * @return  a pointer to the bank
 */
Bank *Cashier::getBank() {
    return _bank;
}