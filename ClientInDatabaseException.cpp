//
// Created by Kacper Murygin on 23/04/2022.
//

#include "ClientInDatabaseException.h"

ClientInDatabaseException::ClientInDatabaseException(int wrongNumber):
        std::invalid_argument("Negative value of the base price: " + std::to_string(wrongNumber)){}
