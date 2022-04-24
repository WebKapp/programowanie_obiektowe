//
// Created by Kacper Murygin on 21/04/2022.
//

#include "client.h"

int Client::getNumber() {
    return number;
}

string Client::getName() {
    return name;
}

void Client::setNumber(int newNumber) {
    number = newNumber;
}

void Client::setName(string newName) {
    name = newName;
}

Client::Client(int Number, string Name) {
    number = Number;
    name = Name;
}


Client::~Client() {}


bool Client::compareNumber(int Number) {
    return number == Number;
}
