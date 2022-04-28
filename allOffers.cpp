//
// Created by Kacper Murygin on 24/04/2022.
//

#include "allOffers.h"
#include <algorithm>
#include <iterator>
using namespace std;

bool AllOffers::checkOfferNumber(int Number) {
    for (const auto &offerPtr: offers) {
        if (offerPtr->getNumber() == Number)
            return true;
    }
    return false;
}

void AllOffers::addOffer(int Number, string Name, string Description, int Rating, int MaxOffers) {
    if(!checkOfferNumber(Number)){
        unique_ptr<Offer> addedOffer = make_unique<Offer>(Number, Name, Description, Rating, MaxOffers);
        offers.push_back(move(addedOffer));
    }
    else
        throw OfferAlreadyExistsException(Number);
}

int AllOffers::getNumberOfOffers() {
    return offers.size();
}

void AllOffers::removeOffer(int number) {
    if (checkOfferNumber(number)){
        auto it = find_if(offers.begin(), offers.end(), [&number](shared_ptr<Offer> obj) {return obj -> getNumber() == number;});
        auto index = distance(offers.begin(), it);
        offers.erase(remove(offers.begin(), offers.end(), offers[index]), offers.end());
    }
    else
        throw NoSuchOfferException(number);
}

vector<shared_ptr<Offer>> AllOffers::getOffers() {
    return offers;
}