//
// Created by Kacper Murygin on 21/04/2022.
//

#include "privateClient.h"
using namespace std;

shared_ptr<Worker> PrivateClient::chooseWorker(AllWorkers Workers) {
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

        for (const auto& workerPtr: workers){
            if (workerPtr -> getAccessible()){
                workerPtr ->setAccessibility(false);
                return workerPtr;
            }
        }

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