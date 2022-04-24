//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_WORKERALREADYEXISTSEXCEPTION_H
#define ZADANIE4_WORKERALREADYEXISTSEXCEPTION_H
#include <stdexcept>
#include <string>
class WorkerAlreadyExistsException : public std::invalid_argument
{
public:
    WorkerAlreadyExistsException(int wrongID);
};
#endif //ZADANIE4_WORKERALREADYEXISTSEXCEPTION_H
