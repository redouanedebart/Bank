//
// Created by redouane on 09/09/22.
//
#include "Bank.h"

using namespace std;

Bank::Bank(int cashierCnt, double expDur, double meanTimeBtwArrivals): DES(){
    _clientCount = 0;
    _cashierCount = cashierCnt;
    _expectedDuration = expDur;
    _meanTimeBetweenArrivals = meanTimeBtwArrivals;
    list<Cashier*> cl;
    _cashierList = cl;
    _queue = WaitingQueue(this);
}

Bank::Bank(const Bank &b) {
    _clientCount = b._clientCount;
    _cashierCount = b._cashierCount;
    _expectedDuration = b._expectedDuration;
    _meanTimeBetweenArrivals = b._meanTimeBetweenArrivals;
    _cashierList = b._cashierList;
}


double Bank::expectedDuration() {
    return _expectedDuration;
}

//TODO changes this function when it will be possible
double Bank::actualDuration() {
    return 1;
}

int Bank::cashierCount() {
    return _cashierCount;
}

int Bank::clientsCount() {
    return _clientCount;
}

Cashier *Bank::firstFreeCashier() {
    return _cashierList.front();
}

double Bank::timeBetweenArrival() {
    return _meanTimeBetweenArrivals;
}

void Bank::addCashiers() {
    for(int i = 0; i< _cashierCount; i++) {//TODO: finish this initialization
        double msd = 0;//how do we determine the duration ? loi de poisson ?
        Cashier cshi(msd, this); //I don't know why I get this error no matching constructor
        _cashierList.push_back(&cshi);
    }
}

//TODO check if we have to redefine DES methods