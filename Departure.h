//
// Created by redouane on 08/09/22.
//
//--------Header Guard-----------//
#ifndef BANK_DEPARTURE_H
#define BANK_DEPARTURE_H

//--------Header files included----//
#include "Event.h"
#include "Client.h"
#include "Bank.h"
#include "Cashier.h"

class Cashier;
//--------Class Prototypes--------//

class Departure: Event{
protected:
    Client* _clientPtr;
    Cashier* _cashierPtr;
public:
    Departure(Client* c, Cashier* cash);
    Departure(){};
    ~Departure();
    void handle();

};
#endif //BANK_DEPARTURE_H
