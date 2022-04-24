//
// Created by Kacper Murygin on 24/04/2022.
//

#include "NoSuchClientInDatabaseException.h"

NoSuchClientInDatabaseException::NoSuchClientInDatabaseException(int wrongNumber):
        std::invalid_argument("No such client in database, number: " + std::to_string(wrongNumber)){}