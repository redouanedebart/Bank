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
    WaitingQueue queue;
    queue = WaitingQueue(this);
    _queue = &queue;
}

/**
* FONCTION AJOUTEE PAR MATTHIEU (24/09/2022)
* Cette renvoi la file d'attente "queue" présente dans la bank
 * modif par Rédouane: n'oublie pas d'ajouter le prototype dans le header la prochaine fois
 * Changed type to WaitingQueue Ptr, added the prototype in header file
 * Forward declaration of class WaitingQueue only allows us to get a ptr to the queue
 * (That's what we wanted from the beginning, so, no worries)
*/
WaitingQueue *Bank::queue(){
    return _queue;
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
    int clientCount;
    for (int i = 0; i < _cashierList.size(); ++i) {
        clientCount += (_cashierList.front()+i)->clientCount();
    }
    return _clientCount;
}

Cashier *Bank::firstFreeCashier() {
    for (int i = 0; i < _cashierList.size(); ++i) {
        if((_cashierList.front()+i)->isFree())
            return (_cashierList.front()+i);
    }
    return NULL;
}

double Bank::timeBetweenArrival() {
    return _meanTimeBetweenArrivals;
}

void Bank::addCashier(double msd) {
    Cashier cshi(msd, this);
    _cashierList.push_back(&cshi);
}

//TODO check if we have to redefine DES methods
