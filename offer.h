//
// Created by Kacper Murygin on 22/04/2022.
//

#ifndef ZADANIE4_OFFER_H
#define ZADANIE4_OFFER_H
#include <string>
#include <iostream>
using namespace std;

class Offer{
protected:
    int number;
    string name;
    string description;
    int rating;
    int maxClients;
    int availableClients;
public:
    Offer(int Number, string Name, string Description, int Rating, int MaxClients);
    int getNumber();
    string getName();
    string getDescription();
    int getRating();
    int getMaxClients();
    int getAvailableClients();

    void increaseAvailableClients();
    void decreaseAvailableClients();
    void setMaxClients(int newMaxClients);
    void setNumber(int newNumber);
    void setName(string newName);
    void setDescription(string newDescription);
    void setRating(int newRating);

    friend ostream& operator<<(ostream& os, const Offer& offer);
};
ostream& operator<<(ostream& os, const Offer& offer);
#endif //ZADANIE4_OFFER_H
