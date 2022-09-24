//
// Created by redouane on 09/09/22.
//
#include "Departure.h"

Departure::~Departure() {}

/**
 * if the waiting getWaitingQueue is empty, the cashier waits, else, the first client is served
 */
// void Departure::handle() {}
void Departure::handle() {
  /**
  * MODIFICATIONS FAITES PAR MATTHIEU (24/09/2022)
  * 
  * Considérons la file d'attente WaitingQueue getWaitingQueue (à récupérer dans la bank)
  * 
  */
  
  /**
  * Remarque: Dans Bank.cpp, une nouvelle fonction a été ajoutée
  * Cette fonction renvoit la file d'attente "_queue" qui se trouve dans la bank
  */
  WaitingQueue queue = bank.getWaitingQueue();
  
  // Si la file d'attente est vide
  if(queue.isEmpty()){
    // Le caissier attend
    // ...
  }
  // Sinon
  else{
    // Le premier client qui arrive est servi par le caissier
    // ...
    
    // Remarque: Je pense qu'il faudra utiliser la fonction "handle()" de Arrival.cpp, quand elle sera prête.
  }
}
