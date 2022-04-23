//
// Created by Kacper Murygin on 21/04/2022.
//

#ifndef ZADANIE4_BUSINESSCLIENT_H
#define ZADANIE4_BUSINESSCLIENT_H
#include "client.h"
#include "worker.h"
#include <vector>
#include <iostream>
using namespace std;

class BusinessClient : public Client{
protected:
public:
    BusinessClient(int Number, string Name);
    shared_ptr<Worker> chooseWorker(vector<shared_ptr<Worker>> workers);
};
#endif //ZADANIE4_BUSINESSCLIENT_H
