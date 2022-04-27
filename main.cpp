#include <iostream>
#include <vector>
#include "client.h"
#include "businessClient.h"
#include "privateClient.h"
#include "allClients.h"
#include "allOffers.h"
#include "offer.h"
#include "worker.h"

using namespace std;

int main()
{
    bool ifContinue = true, okAnswer = true;
    string answer, description;
    AllWorkers workers;
    AllClients clients;
    AllOffers offers;
    int choice, number, id, rating, maxClients;
    string name;

    workers.addWorker(1, "Kamil", 10);
    workers.addWorker(2, "Waclaw", 20);
    workers.addWorker(3, "Konrad", 150);
    workers.addWorker(4, "Konrad", 40);
    workers.addWorker(5, "Konrad", 50);
    workers.addWorker(6, "Konrad", 60);
    workers.addWorker(7, "Konrad", 70);
    workers.addWorker(8, "Konrad", 80);
    workers.addWorker(9, "Konrad", 90);
    workers.addWorker(10, "Konrad", 100);
    workers.addWorker(11, "Konrad", 110);
    workers.addWorker(12, "Konrad", 120);
    workers.addWorker(13, "Konrad", 130);
    workers.addWorker(14, "Konrad", 140);

    while(ifContinue) {
        okAnswer = true;
        cout << "-----------------------MENU-----------------------" << endl;
        cout << "1. Add private client to database" << endl;
        cout << "2. Add business client to database" << endl;
        cout << "3. Remove client from database" << endl;
        cout << "4. Add worker" << endl;
        cout << "5. Add offer" << endl;
        cout << "6. Remove worker" << endl;
        cout << "7. Remove offer" << endl;
        cout << "8. Choose workers for all the clients" << endl;
        cout << "9. Choose offers for all the clients" << endl;

        cin >> choice;
        switch (choice) {
            case 1:
                try {
                    cout << "Number: ";
                    cin >> number;
                    cout << "Name: ";
                    cin >> name;
                    clients.addPrivateClient(number, name);
                }
                catch(const ClientInDatabaseException& e)
                {
                    cerr << e.what() << endl;
                }
                break;
            case 2:
                try {
                    cout << "Number: ";
                    cin >> number;
                    cout << "Name: ";
                    cin >> name;
                    clients.addBusinessClient(number, name);
                }
                catch(const ClientInDatabaseException& e)
                {
                    cerr << e.what() << endl;
                }
                break;
            case 3:
                try{
                    cout << "Number: ";
                    cin >> number;
                    clients.removeClient(number);
                    cout << "Client successfully removed" << endl;
                }
                catch (const NoSuchClientInDatabaseException& e){
                    cerr << e.what() << endl;
                }
                break;
            case 4:
                try {
                    cout << "Id: ";
                    cin >> id;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Rating: ";
                    cin >> rating;
                    workers.addWorker(id, name, rating);
                }
                catch(const WorkerAlreadyExistsException& e){
                    cerr << e.what() << endl;
                }
                break;
            case 5:
                try {
                    cout << "Number: ";
                    cin >> number;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Description: ";
                    cin >> description;
                    cout << "Rating: ";
                    cin >> rating;
                    cout <<"Maximum usage: ";
                    cin >> maxClients;
                    offers.addOffer(number, name, description, rating, maxClients);
                }
                catch(const OfferAlreadyExistsException& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 6:
                try{
                    cout << "Number: ";
                    cin >> number;
                    workers.removeWorker(number);
                    cout << "Worker successfully removed" << endl;
                }
                catch (const NoSuchWorkerException& e){
                    cerr << e.what() << endl;
                }
                break;
            case 7:
                try{
                    cout << "Number: ";
                    cin >> number;
                    offers.removeOffer(number);
                    cout << "Offer successfully removed" << endl;
                }
                catch (const NoSuchOfferException& e){
                    cerr << e.what() << endl;
                }
                break;
            case 8:
                clients.chooseWorkers(workers);
                break;
            case 9 :
                clients.chooseOffers(offers);
                break;
            default:
                cerr << "Wrong choice";
        }
        while(okAnswer) {
            cout << "Do you want to continue? (y/n):";
            cin >> answer;
            for (auto &letter: answer) {
                letter = tolower(letter);
            }
            if (answer == "y" or answer == "yes") {
                ifContinue = true;
                okAnswer = false;
            }
            else if (answer == "n" or answer == "no") {
                ifContinue = false;
                okAnswer = false;
            }
            else {
                cout << "Wrong answer!" << endl;
                okAnswer = true;
            }
        }
    }

    return 0;
}
