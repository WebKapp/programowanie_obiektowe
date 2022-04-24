//
// Created by Kacper Murygin on 21/04/2022.
//

#ifndef ZADANIE4_CLIENT_H
#define ZADANIE4_CLIENT_H
#include <string>
#include <iostream>
#include "NoAvailableWorkerException.h"
#include "worker.h"
#include "offer.h"
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
    virtual shared_ptr<Worker> chooseWorker(vector<shared_ptr<Worker>> workers) = 0;
//    virtual void chooseOffer(vector<unique_ptr<Offer>> offers) = 0;

    friend ostream& operator<<(ostream& os, const Client& client);
};
ostream& operator<<(ostream& os, const Client& client);
#endif //ZADANIE4_CLIENT_H
