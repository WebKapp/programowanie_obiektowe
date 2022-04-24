//
// Created by Kacper Murygin on 22/04/2022.
//

#include "worker.h"

string Worker::getName() {
    return name;
}

double Worker::getRating() {
    return rating;
}

bool Worker::getAccessible() {
    return ifAccessible;
}

int Worker::getId() {
    return id;
}

void Worker::setName(string newName) {
    name = newName;
}

void Worker::setRating(double newRating) {
    rating = newRating;
}

void Worker::setAccessibility(bool newAccessibility) {
    ifAccessible = newAccessibility;
}

Worker::Worker(int Id, string NewName, double Rating, bool IfAccessible) {
    id = Id;
    name = NewName;
    rating = Rating;
    ifAccessible = IfAccessible;
}

bool Worker::operator>(const Worker& secondWorker) const
{
    return rating > secondWorker.rating;
}

bool Worker::operator<(const Worker& secondWorker) const
{
    return !(*this > secondWorker);
}

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << worker.id << "," << worker.name << "," << worker.rating << "," << worker.ifAccessible;
    return os;
}