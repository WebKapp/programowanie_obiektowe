//
// Created by Kacper Murygin on 22/04/2022.
//
#ifndef ZADANIE4_ALLCLIENTS_H
#define ZADANIE4_ALLCLIENTS_H
#include <iostream>
#include <vector>
#include "client.h"
#include <string>
#include <memory>
#include <list>
#include "privateClient.h"
#include "businessClient.h"
#include "ClientInDatabaseException.h"
#include "NoSuchClientInDatabaseException.h"
#include "allWorkers.h"
#include "allOffers.h"
using namespace std;

class AllClients{
private:
    list<unique_ptr<Client>> allClients;
public:
    int getNumberOfClients();

    bool checkClientNumber(int Number);
    void addPrivateClient(int Number, string Name);
    void addBusinessClient(int Number, string Name);
    void removeClient(int Number);

    void chooseWorkers(AllWorkers Workers);
    void chooseOffers(AllOffers Offers);
};
#endif //ZADANIE4_ALLCLIENTS_H
