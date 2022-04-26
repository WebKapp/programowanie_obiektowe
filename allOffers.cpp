//
// Created by Kacper Murygin on 24/04/2022.
//

#include "allOffers.h"
using namespace std;

bool AllOffers::checkOfferNumber(int Number) {
    for (const auto &offerPtr: offers) {
        if (offerPtr->getNumber() == Number)
            return true;
    }
    return false;
}

void AllOffers::addOffer(int Number, string Name, string Description, int Rating) {
    if(!checkOfferNumber(Number)){
        unique_ptr<Offer> addedOffer = make_unique<Offer>(Number, Name, Description, Rating);
        offers.push_back(move(addedOffer));
    }
    else
        throw OfferAlreadyExistsException(Number);
}

int AllOffers::getNumberOfOffers() {
    return offers.size();
}

void AllOffers::removeOffer(int Number) {
    if(checkOfferNumber(Number)){
        for (const auto& offerPtr: offers){
            if (offerPtr -> getNumber() == Number)
                offers.erase(std::remove(offers.begin(), offers.end(), offerPtr), offers.end());
        }
    }
    else
        throw NoSuchOfferException(Number);
}

vector<shared_ptr<Offer>> AllOffers::getOffers() {
    return offers;
}