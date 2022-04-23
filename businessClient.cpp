//
// Created by Kacper Murygin on 21/04/2022.
//
#include "businessClient.h"
using namespace std;

shared_ptr<Worker> BusinessClient::chooseWorker(vector<shared_ptr<Worker>> workers) {
    bool workerNotFound = true;
    int i=0;
    while(workerNotFound){
        if(i >= workers.size()){
            workerNotFound = true;
            cerr << "No available worker";
        }
        else if(workers[i] -> getAccessible()){
            workerNotFound = false;
        }
        else
            i++;
    }
    shared_ptr<Worker> bestWorker = workers[i];
    for (const auto& worker : workers){
        if (worker -> getAccessible()){
            if (worker -> getRating() > bestWorker -> getRating())
                bestWorker = worker;
        }
    }
    return bestWorker;
 }

BusinessClient::BusinessClient(int Number, string Name) :
        Client(Number, Name) {}

