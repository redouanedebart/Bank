//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "Arrival.h"
#include <iostream>
//--------Class Implementation--------//
/**
 *
 * @param triggerTime to know when the event happens
 * @param simPtr points to bank so we can access the cashiers
 */
Arrival::Arrival(double triggerTime, Bank *simPtr): Event(){
    _time = triggerTime;
    _simPtr = simPtr;
}

/**
 * Copy constructor
 * @param arrival reference to an arrival object
 */
Arrival::Arrival(Arrival &arrival){
    _time = arrival._time;
}

Arrival::~Arrival() {}

/**
 * If any Cashier is available, the client goes to the first Cashier available,
 * else, the client is added to the getWaitingQueue
 */
void Arrival::handle() {

    Client client(_time); //create the client

    //check if there is a free cashier to serve the client
    if(!_simPtr.firstFreeCashier()) {
        std::cout << "no free cashier for the moment, the client goes to the waiting queue" << std::endl;
        _simPtr.getWaitingQueue()->addClient(&client) ;
    }else {
        _simPtr.firstFreeCashier()->add
    }
    // Vérifier si le caissier est libre
      // Le caissier en question commence à s'occuper du client
      // ...
      
      // On récupère le nombre de clients servis par le caissier jusqu'à présent
      // Incrémentation du nombre de clients servis par le caissier

      // Attribution de la nouvelle valeur pour le nombre de clients servis par le caissier

      // Le caissier n'est plus libre

      // QUESTION: Faut-il modifier le "_serviceDuration" (mean meanServiceDuration)
      
      // ...
      
      // Mise à jour de la liste (modification du caissier i)

      // Après avoir modifier le caissier i, on sort de la boucle "for"

      
}
    // S'il n'y a pas de caissier libre
    // Il faut ajouter le client à la File d'Attente (WaitingQueue)
    
    // QUESTION: Où se trouve la File D'attente (ex: dans Bank.cpp, Client.cpp, Caishier.cpp, ...)?
    // A REVOIR (pour "getWaitingQueue" et "client")
    // getWaitingQueue.addClient(client)
    


