//
// Created by redouane on 09/09/22.
//
#include "Bank.h"

Bank::Bank(int cashierCnt, double expDur, double meanTimeBtwArrivals) {
    _cashierCount = cashierCnt;
    _expectedDuration = expDur;
    _meanTimeBetweenArrivals = meanTimeBtwArrivals;
    std::list<Cashier*> cl;
    _cashierList = cl;
    for(int i = 0; i< _cashierCount; i++){//TODO: finish this initialization

    }
}

Bank::Bank(Bank &b) {
    _cashierCount = b._cashierCount;
    _expectedDuration = b._expectedDuration;
    _meanTimeBetweenArrivals = b._meanTimeBetweenArrivals;
    _cashierList = b._cashierList;
}

Bank::~Bank() {}

double Bank::expectedDuration() {}

double Bank::actualDuration() {}

int Bank::cashierCount() {}

int Bank::clientsCount() {}

Cashier *Bank::firstFreeCashier() {}

double Bank::timeBetweenArrival() {}

//TODO check if we have to redifines DES methods