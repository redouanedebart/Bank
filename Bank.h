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
#include <iostream>
#include<list>
#include "Cashier.h"
#include "DES.h"

//--------Class Prototypes--------//
class Bank: public DES{
protected:
    int _cashierCount;
    std::list<Cashier*> _cashierList;
    double _expectedDuration;
    double _meanTimeBetweenArrivals;
public:
    Bank(int _cashierCnt, double expDur, double meanTimeBtwArrivals);
    Bank(const Bank& b);
    double expectedDuration();
    int cashierCount();
    double timeBetweenArrival();
    double actualDuration();
    int clientsCount();
    Cashier* firstFreeCashier(); //we need to get null if no one is free, so we use a ptr
};

#endif //BANK_BANK_H
