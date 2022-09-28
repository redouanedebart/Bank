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
    std::queue<Client> _queue;
    Bank* _bank;
    bool _empty;
    double _meanWaitingTime;
    int _maxLength;
    double _meanLength;
public:
    WaitingQueue(Bank* bankPtr);
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
