//
// Created by Kacper Murygin on 22/04/2022.
//

#include "allClients.h"
using namespace std;

bool AllClients::checkClientNumber(int Number) {
    for (const auto &clientPtr: allClients) {
        if (clientPtr->getNumber() == Number)
            return true;
    }
    return false;
}

void AllClients::addPrivateClient(int Number, string Name) {
    if(!checkClientNumber(Number)){
        unique_ptr<PrivateClient> addedClient = make_unique<PrivateClient>(Number, Name);
        allClients.push_back(move(addedClient));
    }
    else
        throw ClientInDatabaseException(Number);
}

void AllClients::addBusinessClient(int Number, string Name) {
    if(!checkClientNumber(Number)) {
        unique_ptr<BusinessClient> addedClient = make_unique<BusinessClient>(Number, Name);
        allClients.push_back(move(addedClient));
    }
    else
        throw ClientInDatabaseException(Number);
}

int AllClients::getNumberOfClients() {
    return allClients.size();
}

void AllClients::removeClient(int Number) {
    if(checkClientNumber(Number)){
        for (const auto& clientPtr: allClients){
            if (clientPtr -> getNumber() == Number)
                allClients.erase(std::remove(allClients.begin(), allClients.end(), clientPtr), allClients.end());
        }
    }
    else
        throw NoSuchClientInDatabaseException(Number);
}

 void AllClients::chooseWorkers(AllWorkers Workers) {
    for (const auto& clientPtr: allClients){
        shared_ptr<Worker> chosenWorker = clientPtr ->chooseWorker(Workers);
        chosenWorker -> setAccessibility(false);
        cout << "For client: " << clientPtr -> getNumber() << " worker:" << chosenWorker -> getId() << endl;
    }
}

void AllClients::chooseOffers(AllOffers Offers) {
    for (const auto& clientPtr: allClients){
        shared_ptr<Offer> chosenOffer = clientPtr ->chooseOffer(Offers);
        cout << "For client: " << clientPtr -> getNumber() << " offer:" << chosenOffer -> getNumber() << endl;
    }
}
