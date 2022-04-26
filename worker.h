//
// Created by Kacper Murygin on 22/04/2022.
//

#ifndef ZADANIE4_WORKER_H
#define ZADANIE4_WORKER_H
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Worker{
private:
    int id;
    string name;
    double rating;
    bool ifAccessible;
public:
    Worker(int Id, string NewName, double Rating, bool IfAccessible=true);
    int getId();
    string getName();
    double getRating();
    bool getAccessible();

    void setID(int newID);
    void setName(string newName);
    void setRating(double newRating);
    void setAccessibility(bool newAccessibility);

    bool operator>(const Worker& secondWorker) const;
    bool operator<(const Worker& secondWorker) const;

    friend ostream& operator<<(ostream& os, const Worker& worker);
};
ostream& operator<<(ostream& os, const Worker& worker);
#endif //ZADANIE4_WORKER_H
