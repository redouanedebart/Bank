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
#include <list>
#include "Event.h"
//--------Class Prototypes--------//

class Event;

class DES{
protected:
    Event* _currentEvent; //pointer to the current event
    //std::priority_queue<Event*, std::vector<Event*>, std::less<Event*>> _evtQueue;
    //uncomment event.h too if I want to try this again (priority_queue)
    std::queue<Event*> _evtQueue; //queue of pointers to event objects: problem with this is: they are not sorted
                                  //I wanted to try priority queue but other errors occurred. Didn't have time to fix it


public:
    std::queue<double> _arrivalTimings;
    explicit DES(Event *evt);
    DES(const DES &d);
    DES() = default;
    ~DES() = default;
    void addEvent(Event& e);
    static double generateEffectiveServiceTime(double value);
    void generateTimings(double meanTimeBetweenArrival, double expectedDur);
    std::queue<Event*> getEvtQueue();
    std::queue<double> getArrivalTimings();
    double getTime();//the time clock for the rest of the program
    void run();
};
#endif //BANK_DES_H
