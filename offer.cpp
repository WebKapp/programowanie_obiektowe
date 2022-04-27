//
// Created by Kacper Murygin on 22/04/2022.
//

#include "offer.h"

Offer::Offer(int Number, string Name, string Description, int Rating, int MaxClients) {
    number = Number;
    name = Name;
    description = Description;
    rating = Rating;
    maxClients = MaxClients;
    availableClients = MaxClients;
}


int Offer::getMaxClients() {
    return maxClients;
}

int Offer::getNumber() {
    return number;
}

string Offer::getName() {
    return name;
}

string Offer::getDescription() {
    return description;
}

int Offer::getRating() {
    return rating;
}

void Offer::setMaxClients(int newMaxClients) {
    maxClients = newMaxClients;
}

void Offer::setNumber(int newNumber) {
    number = newNumber;
}

void Offer::setName(string newName) {
    name = newName;
}

void Offer::setDescription(string newDescription) {
    description = newDescription;
}

void Offer::setRating(int newRating) {
    rating = newRating;
}

ostream& operator<<(ostream& os, const Offer& offer)
{
    os << offer.number << "," << offer.name << "," << offer.description << "," << offer.rating;
    return os;
}

int Offer::getAvailableClients() {
    return availableClients;
}

void Offer::increaseAvailableClients() {
    availableClients += 1;
}

void Offer::decreaseAvailableClients() {
    availableClients -= 1;
}
