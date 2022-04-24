//
// Created by Kacper Murygin on 23/04/2022.
//

#include "NoAvailableWorkerException.h"

NoAvailableWorkerException::NoAvailableWorkerException(string name):
        std::invalid_argument("Client already exists in database, number: "){}
