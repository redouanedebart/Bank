//
// Created by redouane on 08/09/22.
//
//--------Header files included----//
#include "../include/WaitingQueue.h"

//--------Class Implementation--------//
/**
 * WaitingQueue constructor, will be called by Bank()
 * @param bankPtr Pointer on the bank so we can access important information
 * Creates a getWaitingQueue.
 */
WaitingQueue::WaitingQueue(Bank* bankPtr) {
    _bank = bankPtr;
    std::queue<Client> q;
    _queue = q;
    _meanWaitingTime =0;
    _maxLength = 0;
    _meanLength = 0;
    _empty = true;
}

/**
 * method to know if the queue is empty or not
 * @return a boolean, true if the queue is empty
 */
bool WaitingQueue::isEmpty() const {
    return _empty;
}

/**
 * Accessor to the _maxLength field
 * @return the maximum length the getWaitingQueue has had
 */
int WaitingQueue::maxLength() const {
    return _maxLength;
}

/**
 * Accessor to the _meanLength field.
 * The field is updated at every event timing
 * @return the mean length of the getWaitingQueue
 */
double WaitingQueue::meanLength() const {
    return _meanLength;
}

/**
 * accessor to the _meanWaitingTime field
 * @return the mean waiting time for a client in the getWaitingQueue
 */
double WaitingQueue::meanWaitingTime() const {
    return _meanWaitingTime;
}

/**
 * Adds a client to the waiting queue
 * @param c reference to the client
 */
void WaitingQueue::addClient(Client& c) {
    _queue.push(c);
}

/**
 * pop the first client of the getWaitingQueue
 * and returns it
 * @return the client going to be served
 */
Client *WaitingQueue::remove() {
    Client *c = &_queue.front();
    _queue.pop();
    return c;
}

WaitingQueue::~WaitingQueue() = default;