//
// Created by Kacper Murygin on 22/04/2022.
//

#include "allClients.h"
using namespace std;

void AllClients::checkClientNumber(int Number) {

}

void AllClients::addPrivateClient(int Number, string Name) {
    for (const auto& clientPtr: allClients){
        if (clientPtr -> getNumber() == Number)
            throw ClientInDatabaseException(Number);
    }
    unique_ptr<PrivateClient> addedClient = make_unique<PrivateClient>(Number, Name);
    allClients.push_back(move(addedClient));
}

void AllClients::addBusinessClient(int Number, string Name) {
    for (const auto& clientPtr: allClients){
        if (clientPtr -> getNumber() == Number)
            throw ClientInDatabaseException(Number);
    }
    unique_ptr<BusinessClient> addedClient = make_unique<BusinessClient>(Number, Name);
    allClients.push_back(move(addedClient));
}

void AllClients::removeClient(unique_ptr<Client> removedClient) {
    allClients.remove(removedClient);
}
