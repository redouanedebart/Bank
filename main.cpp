//--------Header files included----//
#include <iostream>
#include "Bank.h"
#include "WaitingQueue.h"

//----------------------------//
//----------Main File --------//
//----------------------------//
using namespace std;

int main() {
    int cashierCount;
    double meanTimeBtwArrivals;
    double expectedSimDuration;

    //getting the entry param from console input
    cout<< "\nPlease enter the expected simulation duration:"<<endl;
    cin>>expectedSimDuration;
    cout<< "\nPlease enter the mean time between clients arrival:"<<endl;
    cin>>meanTimeBtwArrivals;
    cout<< "\nPlease enter the cashiers count:"<<endl;
    cin>>cashierCount;

    //creating the bank
    Bank bank(cashierCount, expectedSimDuration, meanTimeBtwArrivals);

    //adding the cashiers
    for (int i = 0; i < bank.cashierCount(); ++i) {
        double serviceTime;
        cout<< "\nPlease enter the mean service duration for cashier number " <<i+1<<endl;
        cin>>serviceTime;
        bank.addCashier(serviceTime);
    }

    //adding the getWaitingQueue
    WaitingQueue q(&bank);
    cout<<"waiting queue created"<<endl;
    bank.addQueue(&q);
    cout<<"running the simulation"<<endl;
    bank.run();

    //returning the results we want, ie actual duration, max and mean length of the getWaitingQueue, the client
    //count (total and per cashier), the occupation rate for each cashier, the mean waiting time for a cashier

    cout<<"Simulation finished\n Results:\n Actual duration:"<<bank.actualDuration()<<endl;
    cout<<"Queue length: max length: "<< bank.getWaitingQueue()->maxLength()<<endl;
    cout << "\tmean length: " << bank.getWaitingQueue()->meanLength() << endl;
    bank.printCashierInfo();
    bank.cashierOccupationRate();
    bank.averageWaitingTime();
    return 0;
}
