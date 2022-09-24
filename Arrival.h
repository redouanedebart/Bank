//
// Created by redouane on 08/09/22.
//
//--------Header Guard-----------//
#ifndef BANK_ARRIVAL_H
#define BANK_ARRIVAL_H

//--------Header files included----//
#include "Event.h"
#include "Bank.h"
#include "Client.h"
//--------Class Prototypes--------//
class Arrival: Event{
protected:
public:
    Arrival(){};
    Arrival(double triggerTime, Bank* simPtr);
    Arrival(Arrival& arrival);
    ~Arrival();
    void handle();//Creates a client
};
#endif //BANK_ARRIVAL_H
