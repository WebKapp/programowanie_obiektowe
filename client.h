//
// Created by Kacper Murygin on 21/04/2022.
//

#ifndef ZADANIE4_CLIENT_H
#define ZADANIE4_CLIENT_H
#include <string>
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

    virtual shared_ptr<Worker> chooseWorker(vector<shared_ptr<Worker>> workers) = 0;
//    virtual void chooseOffer(vector<unique_ptr<Offer>> offers) = 0;
};
#endif //ZADANIE4_CLIENT_H
