//
// Created by Kacper Murygin on 21/04/2022.
//

#ifndef ZADANIE4_BUSINESSCLIENT_H
#define ZADANIE4_BUSINESSCLIENT_H
#include <iostream>
#include <vector>
#include "client.h"

#include "allWorkers.h"
#include "worker.h"
using namespace std;

class BusinessClient : public Client{
public:
    BusinessClient(int Number, string Name);
    shared_ptr<Worker> chooseWorker(AllWorkers workers);
    shared_ptr<Offer> chooseOffer(AllOffers workers);
};

#endif //ZADANIE4_BUSINESSCLIENT_H
