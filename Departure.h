//
// Created by redouane on 08/09/22.
//
//--------Header Guard-----------//
#ifndef BANK_DEPARTURE_H
#define BANK_DEPARTURE_H

//--------Header files included----//
#include "Event.h"

//--------Class Prototypes--------//
class Departure: Event{
protected:
public:
    Departure();
    ~Departure();
    void handle();

};
#endif //BANK_DEPARTURE_H