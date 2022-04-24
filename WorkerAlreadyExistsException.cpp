//
// Created by Kacper Murygin on 24/04/2022.
//

#include "WorkerAlreadyExistsException.h"
WorkerAlreadyExistsException::WorkerAlreadyExistsException(int wrongID):
        std::invalid_argument("Worker already exists in database, number: " + std::to_string(wrongID)){}