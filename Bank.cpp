//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "Bank.h"
#include "Arrival.h"
//--------Class Implementation--------//

using namespace std;
/**
 * constructor for Bank class, takes 3 param:
 * @param cashierCnt the number of cashiers in the bank,
 * @param expDur the expected duration of the simulation
 * @param meanTimeBtwArrivals time between two clients arrival
 */
Bank::Bank(int cashierCnt, double expDur, double meanTimeBtwArrivals): DES(){
    _clientCount = 0;
    _cashierCount = cashierCnt;
    _expectedDuration = expDur;
    _meanTimeBetweenArrivals = meanTimeBtwArrivals;
    list<Cashier*> cl;
    _cashierList = cl;
    _queue = nullptr;
    this->generateTimings(meanTimeBtwArrivals, expDur);
    Arrival arrival(_arrivalTimings.front(), this);
    _arrivalTimings.pop();
    addEvent(arrival);
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

/**
 * Copy constructor
 * @param b
 */
Bank::Bank(const Bank &b): DES(b) {
    _clientCount = b._clientCount;
    _cashierCount = b._cashierCount;
    _expectedDuration = b._expectedDuration;
    _meanTimeBetweenArrivals = b._meanTimeBetweenArrivals;
    _cashierList = b._cashierList;
    _queue = b._queue;
    _evtQueue = b._evtQueue;
    _arrivalTimings = b._arrivalTimings;

}

/**
 *
 * @return the expected duration of the simulation
 */
double Bank::expectedDuration() const {
    return _expectedDuration;
}

/**
 *
 * @return the time when the simulation is finished, ie when all clients have been served
 */
double Bank::actualDuration() {
    if (getTime()>expectedDuration()){
        if (_evtQueue.empty()){
            if (allCashiersFree()) {
                return getTime();
            } else{
                cout << "A cashier is still busy" << endl;
            }
        }
    }
    return -1;
}

/**
 * accessor to _cashierCount field
 * @return the number of cashiers in the bank
 */
int Bank::cashierCount() const {
    return _cashierCount;
}

/**
 * update the field _clientsCount by retrieving the value of the client
 * counter of each cashier
 * @return (int) total number of clients served by the bank
 */
int Bank::totalClientsCount() {
    _clientCount = 0; //resetting the value to avoid unwanted sum in cas of wrong callings
    for (int i = 0; i < _cashierList.size(); ++i) {
        _clientCount += (_cashierList.front()+i)->clientCount();
    }
    return _clientCount;
}

/**
 * Prints the clients count per cashier and in total for the bank, and updates the field
 * clients count in bank so it can be used in another printing method
 */
void Bank::printClientsCount() {
    cout<<"Client count: \n\tper cashier:\n\t";
    for (int i = 0; i < _cashierList.size(); ++i) {
        cout<<"\tcashier "<< i<< ": "<<(_cashierList.front()+i)->clientCount()<<endl;
    }
    cout<<"Client count: total: "<<this->totalClientsCount();

}

/**
 * Get the first free cashier to serve a client
 * @return a pointer to the first cashier available
 */
Cashier *Bank::firstFreeCashier() {
    for (int i = 0; i < _cashierList.size(); ++i) {
        if((_cashierList.front()+i)->isFree())
            return (_cashierList.front()+i);
    }
    return nullptr;
}

/**
 * accessor to the _meanTimeBetweenArrivals field
 * @return the time between two clients arrival (double)
 * NOTE: this is the mean time, not the actual time between two clients arrival.
 * the later is generated randomly using a poisson process
 */
double Bank::timeBetweenArrival() const {
    return _meanTimeBetweenArrivals;
}

/**
 * adds a cashier to the list of cashiers of the bank
 * @param msd mean service duration of this cashier.
 * NOTE: the actual service time vary for each clients served by this cashier
 * cf DES class to see more info about this
 */
void Bank::addCashier(double msd) {
    Cashier cashier(msd, this);
    _cashierList.push_back(&cashier);
}

/**
 * adds the waiting queue of clients to the bank
 */
void Bank::addQueue(WaitingQueue *q) {

    _queue = q;
}

/**
 * Prints the working ratios of each cashiers
 */
void Bank::cashierOccupationRate() {

    cout<<"Cashiers occupation rate:\n\t";
    for (int i = 0; i < _cashierList.size(); ++i) {

        cout<<"\tcashier "<< i<< ": "<<(_cashierList.front()+i)->occupationRate()<<endl;
    }
}

/**
 *
 * @return true if all cashiers are free
 */
bool Bank::allCashiersFree() {
    for (int i = 0; i < _cashierCount; ++i) {
        if (! ( (_cashierList.front()+i)->isFree() ) ) //if a cashier is busy, returns false
            return false;
    }
    return true;
}

/**
 * prints the average waiting time of a customer
 */
void Bank::averageWaitingTime() {
    double waitingTime = 0;
    for (int i = 0; i < _cashierList.size(); ++i) {
        waitingTime += (_cashierList.front()+i)->getWaitingTime();
    }
    waitingTime = waitingTime / this->totalClientsCount();
    cout<<"Average waiting time for a client: "<<waitingTime;
}