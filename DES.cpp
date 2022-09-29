//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "DES.h"
#include "Event.h"
#include<iostream>
//--------Class Implementation--------//

using namespace std;

DES::DES(Event *evt) {
    _currentEvent = evt;
    std::queue<Event*> queue;
    _evtQueue = queue;
    std::queue<double> arr;
    _arrivalTimings = arr;
}

/**
 * copy constructor
 * @param d
 */
DES::DES(const DES &d) {
    _evtQueue = d._evtQueue;
    _currentEvent = d._currentEvent;
    _arrivalTimings = d._arrivalTimings;
}

/**
 * Method that returns the time for other classes
 *
 * @return the current time in the simulation
 */
double DES::getTime() {
   return _currentEvent->getTime();
}

/**
 * starts the clock and generate the schedule for the events
 * using random generators. It is also destroying the events once they are finished
 */
void DES::run() {
    int i = 0;
    while(!_evtQueue.empty()){
        cout<<"event number"<<++i<<endl;
        _currentEvent = _evtQueue.front();
        cout<<"retrieved current event"<<endl;
        _evtQueue.front()->handle();
        _evtQueue.pop();
    }
    getTime();
}

/**
 * Adds an Event to the event list ?
 * @param e is an Event (arrival or departure)
 */
void DES::addEvent(Event& e) {
    _evtQueue.push(&e);
    cout<<"event pushed into queue"<<endl;
}

/**
 * generate random number in between 70% and 130% of the entry value
 * this will be used to generate effective service duration of cashiers
 * @param value mean service duration of cashiers
 * @return effective duration (between 70% and 130% of value)
 */
double DES::generateEffectiveServiceTime(double value) {
    double higherBound = value * 1.3;
    double lowerBound = value * 0.7;
    srand(time(nullptr));
    double randomNumber;
    randomNumber = (double)rand() / higherBound;
    return lowerBound + randomNumber *(higherBound - lowerBound);
}

/**
 * Generating timings of Events (arrivals) using a poisson process,
 *
 * @param meanTimeBetweenArrival the mean time between arrivals
 *
 * The number of arrivals in non-overlapping intervals are statistically independent.
 * The probability of two or more arrivals happening during t is negligible compared
 * to the probability of zero or one arrival, i.e., it is of the order o( t).
 */
void DES::generateTimings(double meanTimeBetweenArrival, double expectedDur) {
    std::random_device rd; // uniformly-distributed integer random number generator to seed
                           //the next line
    std::mt19937 rng (rd ()); // mt19937: Pseudo-random number generation

    double lambda = 1 / meanTimeBetweenArrival;
    std::exponential_distribution<double> exp (lambda);

    double sumArrivalTimes=0;
    double newArrivalTime;
    double safety =0;
    while(safety < expectedDur)
    {
        newArrivalTime=  exp.operator() (rng);// generates the next random number in the distribution
        sumArrivalTimes  += newArrivalTime;
        safety = sumArrivalTimes;
        if(sumArrivalTimes<expectedDur){
            _arrivalTimings.push(sumArrivalTimes);
        }
    }
}

std::queue<Event *> DES::getEvtQueue() {
    return _evtQueue;
}
std::queue<double> DES::getArrivalTimings(){
    return _arrivalTimings;
}