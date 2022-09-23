//
// Created by redouane on 08/09/22.
//
#include "Cashier.h"
#include "Bank.h"
/**
 * Cashier constructor. Will be called by Bank constructor
 * @param meanServiceDuration it is a param since it should be different for every cashier
 * @param bankPtr pointer on the bank, so we can access some infos such as actual duration
 * of the simulation
 * Creates a cashier with a given mean service time.
 */

Cashier::Cashier(double meanServiceDuration, Bank *bankPtr): _bank(bankPtr) {
    _serviceTime = meanServiceDuration;
    _free = true;
    _clientCounter = 0;
}
/**
 * Copy constructor
 * @param c
 */
Cashier::Cashier(const Cashier &c) {
    _serviceTime = c._serviceTime;
    _clientCounter = c._clientCounter;
    _free = c._free;
    _bank = c._bank;
}

/**
 * _clientCounter accessor.
 * @return the number of client served so far by this cashier.
 */
int Cashier::clientCount() {
    return _clientCounter;
}

/**
 * _free accessor
 * @return true if the cashier is available to serve a client
 */
bool Cashier::isFree() {
    return _free;
}

/**
 * mean service duration accessor
 * @return mean service duration of this cashier
 */
double Cashier::meanServiceTime() {
    return _serviceTime;
}

/**
 * Function that computes the occupation rate of this cashier
 * @return returns a double between 0 and 1 representing the percentage
 * of occupation of this cashier.
 */
double Cashier::occupationRate() {
    return (_clientCounter * _serviceTime)/_bank->actualDuration();
}