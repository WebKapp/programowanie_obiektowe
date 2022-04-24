//
// Created by Kacper Murygin on 24/04/2022.
//

#include "NoSuchWorkerException.h"
NoSuchWorkerException::NoSuchWorkerException(int wrongID):
        std::invalid_argument("No such worker in database, number: " + std::to_string(wrongID)){}