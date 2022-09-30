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

class Departure: public Event{
protected:
    Client* _clientPtr; ///pointer to the client
    Cashier* _cashierPtr; ///pointer to the cashier
public:
    Departure(Client* c, Cashier* cash, double time);
    ~Departure();
    void handle() override;

};
#endif //BANK_DEPARTURE_H
