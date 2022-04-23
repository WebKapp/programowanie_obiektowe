//
// Created by Kacper Murygin on 23/04/2022.
//

#ifndef ZADANIE4_CLIENTINDATABASEEXCEPTION_H
#define ZADANIE4_CLIENTINDATABASEEXCEPTION_H
#include <stdexcept>
#include <string>
class ClientInDatabaseException : public std::invalid_argument
{
public:
    ClientInDatabaseException(int wrongNumber);

};

#endif //ZADANIE4_CLIENTINDATABASEEXCEPTION_H
