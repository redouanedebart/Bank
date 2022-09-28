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
    double _actualWorkTime;
    Bank* _bank;
    double _clientsWaitingTime;

public:
    Cashier(double meanServiceDuration, Bank *bankPtr);
    Cashier(const Cashier& c);
    double meanServiceTime() const;
    int clientCount() const;
    double occupationRate();
    bool isFree() const;
    void serve(Client client);
    void wait();
    Bank* getBank();
    double getWaitingTime() const;
};

#endif //BANK_CASHIER_H
