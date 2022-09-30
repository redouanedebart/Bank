//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the cashier class and associated exceptions
 */
//--------Header Guard-----------//
#ifndef BANK_CASHIER_H
#define BANK_CASHIER_H

//--------Header files included----//
#include <iostream>
#include "Client.h"
#include "Bank.h"

//--------Class Prototypes--------//
class Bank;
class Cashier{
protected:
    double _serviceDuration; // the mean service duration for this cashier
    int _clientCounter; //how many clients the cashier served
    bool _free; //true if the cashier is available to serve a client
    double _actualWorkTime; //store the cumulated time of work of that cashier
    Bank* _bank; //pointer to the bank
    double _clientsWaitingTime; //store the waiting time of clients served by this cashier

public:
    Cashier(double meanServiceDuration, Bank *bankPtr);
    Cashier(const Cashier& c);
    int clientCount() const;
    double occupationRate(double actualDur) const;
    bool isFree() const;
    void serve(Client &client);
    void wait();
    Bank* getBank();
    double getWaitingTime() const;
};

#endif //BANK_CASHIER_H
