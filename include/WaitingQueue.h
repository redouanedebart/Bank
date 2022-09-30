//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the WaitingQueue class and related exceptions if any
 */
//--------Header Guard-----------//
#ifndef BANK_WAITINGQUEUE_H
#define BANK_WAITINGQUEUE_H

//--------Header files included----//
#include<iostream>
#include <queue>
#include "Bank.h"
#include "Client.h"

//--------Class Prototypes--------//
class Bank;
class Client;
class WaitingQueue{
protected:
    std::queue<Client> _queue; ///the queue
    Bank* _bank; ///pointer to the bank
    bool _empty; ///true if the queue is empty
    double _meanWaitingTime;
    int _maxLength;
    double _meanLength;
public:
    explicit WaitingQueue(Bank* bankPtr);
    WaitingQueue() = default;
    ~WaitingQueue();
    int maxLength() const;
    double meanLength() const;
    double meanWaitingTime() const;
    void addClient(Client& c);
    bool isEmpty() const;
    Client* remove();
};
#endif //BANK_WAITINGQUEUE_H
