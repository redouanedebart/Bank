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
    _queue = NULL;
}

/**
* FONCTION AJOUTEE PAR MATTHIEU (24/09/2022)
* Cette renvoi la file d'attente "getWaitingQueue" présente dans la bank
 * modif par Rédouane: n'oublie pas d'ajouter le prototype dans le header la prochaine fois
 * Changed type to WaitingQueue Ptr, added the prototype in header file
 * Forward declaration of class WaitingQueue only allows us to get a ptr to the getWaitingQueue
 * (That's what we wanted from the beginning, so, no worries)
*/
WaitingQueue *Bank::getWaitingQueue(){
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

void Bank::clientsCount() {
    int clientCount;
    cout<<"Client count: \n\tper cashier:\n\t";
    for (int i = 0; i < _cashierList.size(); ++i) {
        clientCount += (_cashierList.front()+i)->clientCount();
        cout<<"\tcashier "<< i<< ": "<<(_cashierList.front()+i)->clientCount()<<endl;
    }
    cout<<"Client count: total: "<<clientCount;

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
    Cashier cashier(msd, this);
    _cashierList.push_back(&cashier);
}

void Bank::addQueue() {
    WaitingQueue queue(this);
    _queue = &queue;
}

void Bank::cashierOccupationRate() {

    cout<<"Cashiers occupation rate:\n\t";
    for (int i = 0; i < _cashierList.size(); ++i) {

        cout<<"\tcashier "<< i<< ": "<<(_cashierList.front()+i)->occupationRate()<<endl;
    }
}
//TODO check if we have to redefine DES methods
