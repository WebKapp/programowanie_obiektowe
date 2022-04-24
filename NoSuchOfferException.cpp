//
// Created by Kacper Murygin on 24/04/2022.
//

#include "NoSuchOfferException.h"

NoSuchOfferException::NoSuchOfferException(int wrongNumber):
        std::invalid_argument("No such offer in database, number: " + std::to_string(wrongNumber)){}