//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the Discrete Event Simulation (DES) class and related exceptions
 */
//--------Header Guard-----------//
#ifndef BANK_DES_H
#define BANK_DES_H

//--------Header files included----//
#include "Event.h"
#include<chrono>
#include <ctime>
#include <random>

//--------Class Prototypes--------//
class DES{
protected:
    double _startTime;
    double _stopTime;
    double _diffTime;
    std::default_random_engine _generator;
public:
    DES(){};
    ~DES();
    void addEvent(Event e);
    void run();
    double getTime();//the time clock for the rest of the program
};
#endif //BANK_DES_H
