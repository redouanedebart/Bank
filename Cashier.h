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
class Cashier{
protected:
    double _serviceTime; // the mean service duration for this cashier
    int _clientCounter; //how many clients the cashier served
    bool _free; //true if the cashier is available to serve a client
    Bank* _bank;
public:
    Cashier(double meanServiceDuration, Bank *bankPtr);
    Cashier(const Cashier& c);
    double meanServiceTime();
    int clientCount();
    double occupationRate();
    bool isFree();
    void serve(Client client);
    void wait();

};

#endif //BANK_CASHIER_H
