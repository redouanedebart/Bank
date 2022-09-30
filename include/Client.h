//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the Client class and the related exceptions if any
 */
//--------Header Guard-----------//
#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H

//--------Header files included----//

//--------Class Prototypes--------//
class Client{
protected:
    double _time; //time of arrival
public:
    explicit Client(double arrivalTime);
    ~Client();
    double arrivalTime() const;

};
#endif //BANK_CLIENT_H
