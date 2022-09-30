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
    WaitingQueue* _queue; //pointer to the waiting queue
    int _cashierCount;  //number of cashiers in the bank
    int _clientCount; //field to store the total number of cashier at the end of the simulation
    std::list<Cashier*> _cashierList; //list of cashiers at the bank
    double _expectedDuration; //the expected duration of the simulation
    double _meanTimeBetweenArrivals; //average time between clients arrivals
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
    void printCashierInfo();
    int totalClientsCount();
};

#endif //BANK_BANK_H
