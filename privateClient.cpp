//
// Created by Kacper Murygin on 21/04/2022.
//

#include "privateClient.h"
using namespace std;

shared_ptr<Worker> PrivateClient::chooseWorker(AllWorkers Workers) {
    vector<shared_ptr<Worker>> workers = Workers.getWorkers();
    for(int i=0; i< Workers.getNumberOfWorkers(); i++) {
        if(workers[i] -> getAccessible()) {
            workers[i]->setAccessibility(false);
            return workers[i];
        }
    }
    throw NoAvailableWorkerException(name);
}

PrivateClient::PrivateClient(int Number, string Name) :
        Client(Number, Name) {}

shared_ptr<Offer> PrivateClient::chooseOffer(AllOffers Offers) {
    vector<shared_ptr<Offer>> offers = Offers.getOffers();
    for(int i=0; i< Offers.getNumberOfOffers(); i++) {
        if(offers[i] -> getAvailableClients() > 0) {
            offers[i]->decreaseAvailableClients();
            return offers[i];
        }
    }
    throw NoAvailableOfferException(name);
}