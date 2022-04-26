//
// Created by Kacper Murygin on 21/04/2022.
//

#ifndef ZADANIE4_PRIVATECLIENT_H
#define ZADANIE4_PRIVATECLIENT_H
#include <vector>
#include <iostream>
#include "client.h"
#include "worker.h"
#include "allWorkers.h"
#include "allClients.h"
class PrivateClient : public Client{
protected:
public:
    PrivateClient(int Number, string Name);
    shared_ptr<Worker> chooseWorker(AllWorkers workers);
    shared_ptr<Offer> chooseOffer(AllOffers offers);
};
#endif //ZADANIE4_PRIVATECLIENT_H
