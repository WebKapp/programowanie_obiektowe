//
// Created by Kacper Murygin on 21/04/2022.
//

#include "privateClient.h"
using namespace std;

shared_ptr<Worker> PrivateClient::chooseWorker(vector<shared_ptr<Worker>> workers) {
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
    //TO DO- MUSZA BYC WLACZONE
    workerNotFound = true;
    while(workerNotFound){
        srand( (unsigned)time(NULL) );
        int workerNumber = rand() % workers.size();
        return workers[workerNumber];
    }
}

PrivateClient::PrivateClient(int Number, string Name) :
        Client(Number, Name) {}