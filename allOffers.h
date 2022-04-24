//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_ALLOFFERS_H
#define ZADANIE4_ALLOFFERS_H
#include "offer.h"
#include "NoSuchOfferException.h"
#include "OfferAlreadyExistsException.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <list>
class AllOffers{
private:
    list<unique_ptr<Offer>> offers;
public:
    int getNumberOfOffers();
    bool checkOfferNumber(int Number);
    void addOffer(int Number, string Name, string Description, int Rating);
    void removeOffer(int Number);
};
#endif //ZADANIE4_ALLOFFERS_H
