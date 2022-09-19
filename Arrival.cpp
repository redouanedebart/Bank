//
// Created by redouane on 09/09/22.
//
#include "Arrival.h"

Arrival::Arrival() {} //TODO: check implementation of derived classes in poste project,
                    //for this class and departure class

/**
 * Copy constructor
 * @param arrival reference to an arrival object
 */
Arrival::Arrival(Arrival &arrival) {
    _time = arrival._time;
}

Arrival::~Arrival() {}

/**
 * If any Cashier is available, the client goes to the first Cashier available,
 * else, the client is added to the queue
 */
void Arrival::handle() {
  
  // MODIFICATION APPORTEES PAR MATTHIEU SAUVAGEOT (19/09/2022)
  
  // Parcours de la liste _cashierList (voir Bank.h)
  for(i=0; i< _cashierList.size();i++){
    
    // Récupération du caissier i
    Cashier cashier_i = _cashierList[i];
    
    // Vérifier si le caissier est libre
    if(cashier_i.isFree()){
      // Le caissier en question commence à s'occuper du client
      // ...
      
      // On récupère le nombre de clients servis par le caissier jusqu'à présent
      int nbClients = caissier_i.clientCount();
      
      // Incrémentation du nombre de clients servis par le caissier
      nbClients+=1;
      
      // Attribution de la nouvelle valeur pour le nombre de clients servis par le caissier
      cashier_i._clientCounter = nbClients;
      
      // Le caissier n'est plus libre
      cashier_i._free = 'false';
      
      // QUESTION: Faut-il modifier le "_serviceTime" (mean meanServiceDuration)
      
      // ...
      
      // Mise à jour de la liste (modification du caissier i)
      cashierList[i] = cashier_i;
      
      // Après avoir modifier le caissier i, on sort de la boucle "for"
      exit 0;
      
    }
    // S'il n'y a pas de caissier libre
    // Il faut ajouter le client à la File d'Attente (WaitingQueue)
    
    // QUESTION: Où se trouve la File D'attente (ex: dans Bank.cpp, Client.cpp, Caishier.cpp, ...)?
    // A REVOIR (pour "queue" et "client")
    // queue.addClient(client)
    
  }
}
