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
    WaitingQueue* _queue;
    int _cashierCount;
    int _clientCount;
    std::list<Cashier*> _cashierList;
    double _expectedDuration;
    double _meanTimeBetweenArrivals;
public:
    Bank(int _cashierCnt, double expDur, double meanTimeBtwArrivals);
    Bank(const Bank& b);
    double actualDuration();
    void addCashier(double msd);
    void addQueue(WaitingQueue *q);
    bool allCashiersFree();
    void averageWaitingTime();
    int cashierCount() const;
    void cashierOccupationRate();
    double expectedDuration() const;
    Cashier* firstFreeCashier();
    WaitingQueue* getWaitingQueue();
    void printClientsCount();
    int totalClientsCount();
};

#endif //BANK_BANK_H
