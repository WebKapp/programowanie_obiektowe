//
// Created by Kacper Murygin on 27/04/2022.
//

#include "NoAvailableOfferException.h"

NoAvailableOfferException::NoAvailableOfferException(string name):
        std::invalid_argument("Client already exists in database, number: "){}