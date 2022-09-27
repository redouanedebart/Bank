//
// Created by redouane on 08/09/22.
//
#include "WaitingQueue.h"

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
}

bool WaitingQueue::isEmpty() {
    return _empty;
}
/**
 * Accessor to the _maxLength field
 * @return the maximum length the getWaitingQueue has had
 */
int WaitingQueue::maxLength() {
    return _maxLength;
}

//At which moment do we check the
// size of the getWaitingQueue ? each event ? should we store the values ?
/**
 * Accessor to the _meanLength field.
 * The field is updated at every event timing
 * @return the mean length of the getWaitingQueue
 */
double WaitingQueue::meanLength() {
    return _meanLength;
}

/**
 * accessor to the _meanWaitingTime field
 * @return the mean waiting time for a client in the getWaitingQueue
 */
double WaitingQueue::meanWaitingTime() {
    return _meanWaitingTime;
}

void WaitingQueue::addClient(Client& c) {
    _queue.push(c);
}

/**
 * pop the first client of the getWaitingQueue
 * @return the client going to be served
 */
Client *WaitingQueue::remove() {
    Client *c = &_queue.front();
    _queue.pop();
    return c;
}

WaitingQueue::~WaitingQueue() = default;