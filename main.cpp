#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    int cashierCount;
    double meanTimeBtwArrivals;
    double expectedSimDuration;

    cout<< "\nPlease enter the expected simulation duration:"<<endl;
    cin>>expectedSimDuration;
    cout<< "\nPlease enter the mean time between clients arrival:"<<endl;
    cin>>meanTimeBtwArrivals;
    cout<< "\nPlease enter the cashiers count:"<<endl;
    cin>>cashierCount;

    Bank bank(cashierCount, expectedSimDuration, meanTimeBtwArrivals);

    for (int i = 0; i < cashierCount; ++i) {
        double serviceTime;
        cout<< "\nPlease enter the mean service duration for cashier number " <<i+1<<endl;
        cin>>serviceTime;
        bank.addCashier(serviceTime);
    }

    for (string line; getline(cin, line);) {
        cout << line << endl;
    }

    return 0;
}
