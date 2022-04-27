//
// Created by Kacper Murygin on 27/04/2022.
//

#ifndef ZADANIE4_NOAVAILABLEOFFEREXCEPTION_H
#define ZADANIE4_NOAVAILABLEOFFEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class NoAvailableOfferException : public std::invalid_argument
{
public:
    NoAvailableOfferException(string name);

};
#endif //ZADANIE4_NOAVAILABLEOFFEREXCEPTION_H
