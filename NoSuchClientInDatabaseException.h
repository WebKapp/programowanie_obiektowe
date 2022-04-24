//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_NOSUCHCLIENTINDATABASEEXCEPTION_H
#define ZADANIE4_NOSUCHCLIENTINDATABASEEXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class NoSuchClientInDatabaseException : public std::invalid_argument
{
public:
    NoSuchClientInDatabaseException(int wrongNumber);

};
#endif //ZADANIE4_NOSUCHCLIENTINDATABASEEXCEPTION_H
