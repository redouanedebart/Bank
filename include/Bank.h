//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the Bank class and the related exceptions
 */
//--------Header Guard-----------//
#ifndef BANK_BANK_H
#define BANK_BANK_H

//--------Header files included----//
#include "DES.h"
#include <iostream>
#include <list>
#include "Cashier.h"
#include "WaitingQueue.h"

//--------Class Prototypes--------//
class WaitingQueue;
class Cashier;

class Bank: public DES{
protected:
    WaitingQueue* _queue; ///pointer to the waiting queue
    int _cashierCount;  ///number of cashiers in the bank
    int _clientCount; ///field to store the total number of cashier at the end of the simulation
    std::list<Cashier*> _cashierList; ///list of cashiers at the bank
    double _expectedDuration; ///the expected duration of the simulation
    double _meanTimeBetweenArrivals; ///average time between clients arrivals
public:
    Bank(int _cashierCnt, double expDur, double meanTimeBtwArrivals);
    Bank(const Bank& b);
    double actualDuration(); ///returns the actual duration of the simulation
    void addCashier(double msd); ///adds a cashier to the list
    void addQueue(WaitingQueue *q); ///add the waiting queue to the bank
    bool allCashiersFree(); ///true if all the cashiers are available
    void averageWaitingTime(); ///for the client
    int cashierCount() const; /// number of cashiers
    void cashierOccupationRate(); /// how busy a cashier is
    double expectedDuration() const;
    Cashier* firstFreeCashier();
    WaitingQueue* getWaitingQueue();
    void printCashierInfo();
    int totalClientsCount();
};

#endif //BANK_BANK_H
