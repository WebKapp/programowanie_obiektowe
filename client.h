//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_CLIENT_H
#define ZADANIE4_CLIENT_H
#include <string>
#include <ostream>
#include <iostream>
#include "NoAvailableWorkerException.h"
#include "NoAvailableOfferException.h"
#include "worker.h"
#include "offer.h"
#include "allOffers.h"
#include "allWorkers.h"
using namespace std;

class Client {
protected:
    int number;
    string name;
public:
    Client(int Number, string Name);
    int getNumber();
    string getName();
    virtual ~Client();

    void setNumber(int newNumber);
    void setName(string newName);

    bool compareNumber(int Number);
    virtual shared_ptr<Worker> chooseWorker(AllWorkers workers) = 0;
    virtual shared_ptr<Offer> chooseOffer(AllOffers workers) = 0;

    friend ostream& operator<<(ostream& os, const Client& client);
};
ostream& operator<<(ostream& os, const Client& client);
#endif //ZADANIE4_CLIENT_H
