//
// Created by Kacper Murygin on 21/04/2022.
//

#ifndef ZADANIE4_PRIVATECLIENT_H
#define ZADANIE4_PRIVATECLIENT_H
#include "client.h"
#include "worker.h"
#include <vector>
#include <iostream>
class PrivateClient : public Client {
protected:
public:
    PrivateClient(int Number, string Name);
    shared_ptr<Worker> chooseWorker(vector<shared_ptr<Worker>> workers);
};
#endif //ZADANIE4_PRIVATECLIENT_H
