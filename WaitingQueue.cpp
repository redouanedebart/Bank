//
// Created by redouane on 08/09/22.
//
#include "WaitingQueue.h"

/**
 * WaitingQueue constructor, will be called by Bank()
 * @param bankPtr Pointer on the bank so we can access important information
 * Creates a queue.
 */
WaitingQueue::WaitingQueue(Bank* bankPtr) {
    _bank = bankPtr;
    std::queue<Client> q;
    _queue = q;
}

bool WaitingQueue::isEmpty() {
    return _empty;
}
//TODO: Complete these functions
int WaitingQueue::maxLength() {}

double WaitingQueue::meanLength() {}//At which moment do we check the
// size of the queue ? each event ? should we store the values ?

double WaitingQueue::meanWaitingTime() {}

void WaitingQueue::addClient(Client c) {}

/**
 * pop the first client of the queue
 * @return the client going to be served
 */
Client *WaitingQueue::remove() {
    return _queue.pop();
}

WaitingQueue::~WaitingQueue() {}