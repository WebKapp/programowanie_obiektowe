//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_NOSUCHWORKEREXCEPTION_H
#define ZADANIE4_NOSUCHWORKEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NoSuchWorkerException : public std::invalid_argument
{
public:
    NoSuchWorkerException(int wrongID);
};
#endif //ZADANIE4_NOSUCHWORKEREXCEPTION_H
