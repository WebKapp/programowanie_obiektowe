//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_OFFERALREADYEXISTSEXCEPTION_H
#define ZADANIE4_OFFERALREADYEXISTSEXCEPTION_H
#include <stdexcept>
#include <string>
class OfferAlreadyExistsException : public std::invalid_argument
{
public:
    OfferAlreadyExistsException(int wrongNumber);
};
#endif //ZADANIE4_OFFERALREADYEXISTSEXCEPTION_H
