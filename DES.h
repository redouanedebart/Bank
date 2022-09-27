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
#include<queue>
#include<chrono>
#include <ctime>
#include <random>
#include <cstdlib>

//--------Class Prototypes--------//

class Event;

class DES{
protected:
    double _startTime;
    double _stopTime;
    double _diffTime;
    std::queue<Event*> _evtQueue;
public:
    DES(){};
    ~DES();
    void addEvent(Event e);
    double generateEffectiveServiceTime(double value);
    void generateTimings(double meanTimeBetweenArrival, double expectedDur);
    double getTime();//the time clock for the rest of the program
    void run();
};
#endif //BANK_DES_H
