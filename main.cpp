#include <iostream>
#include <vector>
#include "client.h"
#include "businessClient.h"
#include "privateClient.h"
#include "allClients.h"
#include "offer.h"
#include "worker.h"
#include <typeinfo>
using namespace std;

int main() {

//    void AllClients::addClient(unique_ptr<Client> newClient) {
//        allClients.push_back(move(newClient));
//    }

    vector<shared_ptr<Worker>> workers;
//    workers.push_back(make_unique<Worker>("Kamila"));
    auto worker1 = make_shared<Worker>(3, "Kamilas", 15, false);
    auto worker2 = make_shared<Worker>(2, "Kamil", 11, true);
    auto worker3 = make_shared<Worker>(1, "Marta", 12, false);
    workers.push_back(move(worker1));
    workers.push_back(move(worker2));
    workers.push_back(move(worker3));
//    for (const auto& worker: workers){
//        cout << worker->getName() << endl;
//    }

//    bool a;
//    a = workers[0] < workers[1];
//    cout << a;

    BusinessClient klient1( 99, "Kamil");
    cout <<  klient1.chooseWorker(workers) -> getName();

    cout << endl;
    PrivateClient klient2(90, "Marcin");
    cout <<  klient2.chooseWorker(workers) -> getName();


    AllClients clients;
    clients.addBusinessClient(14, "Kamil");
    clients.addBusinessClient(13, "Kamil");
    clients.addBusinessClient(12, "Kamil");

    cout << clients.getNumberOfClients();

    clients.addBusinessClient(15, "Kamil");

    cout << clients.getNumberOfClients();

    clients.removeClient(12);
    cout << clients.getNumberOfClients();

//    Client* client1 = new Client();
//    int i = 10;
//    int *ptr = &i;
//    cout << ptr << endl;
//    *ptr = 12;
//    cout << i << endl;
    return 0;
}
