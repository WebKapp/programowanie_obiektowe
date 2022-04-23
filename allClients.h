//
// Created by Kacper Murygin on 22/04/2022.
//

#ifndef ZADANIE4_ALLCLIENTS_H
#define ZADANIE4_ALLCLIENTS_H
#include "client.h"
#include "privateClient.h"
#include "businessClient.h"
#include "ClientInDatabaseException.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <list>
class AllClients{
private:
    list<unique_ptr<Client>> allClients;
public:
    void addPrivateClient(int Number, string Name);
    void addBusinessClient(int Number, string Name);
    void removeClient(unique_ptr<Client> removedClient);
};
#endif //ZADANIE4_ALLCLIENTS_H
