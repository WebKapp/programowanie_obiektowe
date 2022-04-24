//
// Created by Kacper Murygin on 24/04/2022.
//

#include "OfferAlreadyExistsException.h"
OfferAlreadyExistsException::OfferAlreadyExistsException(int wrongNumber):
        std::invalid_argument("Offert already exists in database, number: " + std::to_string(wrongNumber)){}