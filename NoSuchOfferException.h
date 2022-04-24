//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_NOSUCHOFFEREXCEPTION_H
#define ZADANIE4_NOSUCHOFFEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NoSuchOfferException : public std::invalid_argument
{
public:
    NoSuchOfferException(int wrongNumber);
};
#endif //ZADANIE4_NOSUCHOFFEREXCEPTION_H
