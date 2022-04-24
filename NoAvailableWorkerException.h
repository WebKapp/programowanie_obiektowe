//
// Created by Kacper Murygin on 23/04/2022.
//

#ifndef ZADANIE4_NOAVAILABLEWORKEREXCEPTION_H
#define ZADANIE4_NOAVAILABLEWORKEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class NoAvailableWorkerException : public std::invalid_argument
{
public:
    NoAvailableWorkerException(string name);

};
#endif //ZADANIE4_NOAVAILABLEWORKEREXCEPTION_H
