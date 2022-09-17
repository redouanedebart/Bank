//
// Created by redouane on 09/09/22.
//
#include "Bank.h"

using namespace std;

Bank::Bank(int cashierCnt, double expDur, double meanTimeBtwArrivals): DES(){
    _cashierCount = cashierCnt;
    _expectedDuration = expDur;
    _meanTimeBetweenArrivals = meanTimeBtwArrivals;
    list<Cashier*> cl;
    _cashierList = cl;
    for(int i = 0; i< _cashierCount; i++){//TODO: finish this initialization
        double msd = 0;//how do we determine the duration ? loi de poisson ?
        Bank* self;
        self = this;
        Cashier cshi(msd, &self); //I don't know why I get this error no matching constructor
        cl.push_back(&cshi);
    }
}

Bank::Bank(const Bank &b) {
    _cashierCount = b._cashierCount;
    _expectedDuration = b._expectedDuration;
    _meanTimeBetweenArrivals = b._meanTimeBetweenArrivals;
    _cashierList = b._cashierList;
}


double Bank::expectedDuration() {}

double Bank::actualDuration() {}

int Bank::cashierCount() {}

int Bank::clientsCount() {}

Cashier *Bank::firstFreeCashier() {}

double Bank::timeBetweenArrival() {}

//TODO check if we have to redefine DES methods