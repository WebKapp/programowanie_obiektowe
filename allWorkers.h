//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef ZADANIE4_ALLWORKERS_H
#define ZADANIE4_ALLWORKERS_H
#include "worker.h"
#include "NoSuchWorkerException.h"
#include "WorkerAlreadyExistsException.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <list>
class AllWorkers{
private:
    vector<shared_ptr<Worker>> workers;
public:
    int getNumberOfWorkers();
    bool checkWorkerNumber(int Id);
    void addWorker(int Id, string NewName, double Rating, bool IfAccessible=true);
    void removeWorker(int Id);

    vector<shared_ptr<Worker>> getWorkers();
};
#endif //ZADANIE4_ALLWORKERS_H
