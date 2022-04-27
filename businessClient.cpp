//
// Created by Kacper Murygin on 21/04/2022.
//
#include "businessClient.h"

shared_ptr<Worker> BusinessClient::chooseWorker(AllWorkers Workers) {
    vector<shared_ptr<Worker>> workers = Workers.getWorkers();
    bool workerNotFound = true;
    int i=0;
    while(workerNotFound){
        if(i >= workers.size()){
            workerNotFound = true;
            throw NoAvailableWorkerException(name);
        }
        else if(workers[i] -> getAccessible()){
            workerNotFound = false;
        }
        else
            i++;
    }
    shared_ptr<Worker> bestWorker = workers[i];
    for (const auto& worker : workers){
        if (worker -> getAccessible()){
            if (worker -> getRating() > bestWorker -> getRating())
                bestWorker = worker;
        }
    }
    bestWorker -> setAccessibility(false);
    return bestWorker;
 }

BusinessClient::BusinessClient(int Number, string Name) :
        Client(Number, Name) {}

shared_ptr<Offer> BusinessClient::chooseOffer(AllOffers Offers) {
    vector<shared_ptr<Offer>> offers = Offers.getOffers();
    shared_ptr<Offer> bestOffer;
    bool ifFound = false;
    for (const auto& offer : offers){
        if(offer -> getAvailableClients() > 0){
            ifFound = true;
            bestOffer = offer;
            break;
        }
    }
    if(!ifFound)
        throw NoAvailableOfferException(name);

    for (const auto& offer : offers){
            if (offer -> getRating() > bestOffer -> getRating() and offer -> getAvailableClients() > 0)
                bestOffer = offer;
    }
    bestOffer -> decreaseAvailableClients();
    return bestOffer;
    }

