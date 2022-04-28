//
// Created by Kacper Murygin on 24/04/2022.
//
#include <iostream>
#include <vector>
#include "catch.hh"
#include "../client.h"
#include "../businessClient.h"
#include "../privateClient.h"
#include "../allClients.h"
#include "../allOffers.h"
#include "../offer.h"
#include "../worker.h"
using namespace std;
TEST_CASE("product simple tests", "[clients]")
{
    SECTION("class privateClient"){
        PrivateClient client1(1, "Kamila");
        CHECK(client1.getNumber() == 1);
        CHECK(client1.getName() == "Kamila");

        client1.setNumber(12);
        client1.setName("Konrad");
        CHECK(client1.getNumber() == 12);
        CHECK(client1.getName() == "Konrad");
    }

    SECTION("class businessClient"){
        BusinessClient client1(1, "Kamila");
        CHECK(client1.getNumber() == 1);
        CHECK(client1.getName() == "Kamila");

        client1.setNumber(12);
        client1.setName("Konrad");
        CHECK(client1.getNumber() == 12);
        CHECK(client1.getName() == "Konrad");
    }

    SECTION("choosing workers for privateClient"){
        AllWorkers workers;
        workers.addWorker(1, "Kamil", 10);
        workers.addWorker(2, "Waclaw", 200);
        workers.addWorker(3, "Konrad", 150);
        workers.addWorker(4, "Gustaw", 40);

        PrivateClient client1(1, "Kamila");
        PrivateClient client2(2, "Kamil");

        shared_ptr<Worker> workerFor1 = client1.chooseWorker(workers);
        shared_ptr<Worker> workerFor2 = client2.chooseWorker(workers);

        CHECK(workerFor1 -> getId() == 1);
        CHECK(workerFor2 -> getId() == 2);
    }

    SECTION("choosing workers for businessClient"){
        AllWorkers workers;
        workers.addWorker(1, "Kamil", 10);
        workers.addWorker(2, "Waclaw", 200);
        workers.addWorker(3, "Konrad", 150);
        workers.addWorker(4, "Gustaw", 40);

        BusinessClient client1(1, "Kamila");
        BusinessClient client2(2, "Kamil");

        shared_ptr<Worker> workerFor1 = client1.chooseWorker(workers);
        shared_ptr<Worker> workerFor2 = client2.chooseWorker(workers);

        CHECK(workerFor1 -> getId() == 2);
        CHECK(workerFor2 -> getId() == 3);
    }
    SECTION("choosing workers for privateClient- no available worker"){
        AllWorkers workers;
        workers.addWorker(1, "Kamil", 10);

        PrivateClient client1(1, "Kamila");
        PrivateClient client2(2, "Kamil");

        shared_ptr<Worker> workerFor1 = client1.chooseWorker(workers);
        CHECK_THROWS_AS(client2.chooseWorker(workers), NoAvailableWorkerException);
    }
    SECTION("choosing workers for businessClient- no available worker"){
        AllWorkers workers;
        workers.addWorker(1, "Kamil", 10);

        BusinessClient client1(1, "Kamila");
        BusinessClient client2(2, "Kamil");

        shared_ptr<Worker> workerFor1 = client1.chooseWorker(workers);
        CHECK_THROWS_AS(client2.chooseWorker(workers), NoAvailableWorkerException);
    }
    SECTION("choosing workers- both types of clients"){
        AllWorkers workers;
        workers.addWorker(1, "Kamil", 10);
        workers.addWorker(2, "Waclaw", 20);
        workers.addWorker(3, "Konrad", 30);
        workers.addWorker(4, "Gustaw", 40);

        BusinessClient client1(1, "Kamila");
        BusinessClient client2(2, "Kamil");
        PrivateClient client3(3, "Kamila");
        PrivateClient client4(4, "Kamil");

        shared_ptr<Worker> workerFor1 = client1.chooseWorker(workers);
        shared_ptr<Worker> workerFor2 = client2.chooseWorker(workers);
        shared_ptr<Worker> workerFor3 = client3.chooseWorker(workers);
        shared_ptr<Worker> workerFor4 = client4.chooseWorker(workers);

        CHECK(workerFor1 -> getId() == 4);
        CHECK(workerFor2 -> getId() == 3);
        CHECK(workerFor3 -> getId() == 1);
        CHECK(workerFor4 -> getId() == 2);
    }
    SECTION("choosing offers for businessClient"){
        AllOffers offers;
        offers.addOffer(1, "specjalna 1", "Kup 2 w 1", 35, 2);
        offers.addOffer(2, "specjalna 1", "Kup 2 w 1", 20, 2);
        offers.addOffer(3, "specjalna 1", "Kup 2 w 1", 300, 1);
        offers.addOffer(4, "specjalna 1", "Kup 2 w 1", 40, 1);
        offers.addOffer(5, "specjalna 1", "Kup 2 w 1", 50, 2);

        BusinessClient client1(1, "Kamila");
        BusinessClient client2(2, "Kamil");
        BusinessClient client3(3, "Kamil");
        BusinessClient client4(4, "Kamil");
        BusinessClient client5(5, "Kamil");

        shared_ptr<Offer> offerFor1 = client1.chooseOffer(offers);
        shared_ptr<Offer> offerFor2 = client2.chooseOffer(offers);
        shared_ptr<Offer> offerFor3 = client3.chooseOffer(offers);
        shared_ptr<Offer> offerFor4 = client4.chooseOffer(offers);
        shared_ptr<Offer> offerFor5 = client5.chooseOffer(offers);

        CHECK(offerFor1 -> getNumber() == 3);
        CHECK(offerFor2 -> getNumber() == 5);
        CHECK(offerFor3 -> getNumber() == 5);
        CHECK(offerFor4 -> getNumber() == 4);
        CHECK(offerFor5 -> getNumber() == 1);
    }

    SECTION("choosing offers for privateClient"){
        AllOffers offers;
        offers.addOffer(1, "specjalna 1", "Kup 2 w 1", 35, 2);
        offers.addOffer(2, "specjalna 1", "Kup 2 w 1", 20, 1);
        offers.addOffer(3, "specjalna 1", "Kup 2 w 1", 300, 1);
        offers.addOffer(4, "specjalna 1", "Kup 2 w 1", 40, 1);
        offers.addOffer(5, "specjalna 1", "Kup 2 w 1", 50, 2);

        PrivateClient client1(1, "Kamila");
        PrivateClient client2(2, "Kamil");
        PrivateClient client3(3, "Kamil");
        PrivateClient client4(4, "Kamil");
        PrivateClient client5(5, "Kamil");

        shared_ptr<Offer> offerFor1 = client1.chooseOffer(offers);
        shared_ptr<Offer> offerFor2 = client2.chooseOffer(offers);
        shared_ptr<Offer> offerFor3 = client3.chooseOffer(offers);
        shared_ptr<Offer> offerFor4 = client4.chooseOffer(offers);
        shared_ptr<Offer> offerFor5 = client5.chooseOffer(offers);

        CHECK(offerFor1 -> getNumber() == 1);
        CHECK(offerFor2 -> getNumber() == 1);
        CHECK(offerFor3 -> getNumber() == 2);
        CHECK(offerFor4 -> getNumber() == 3);
        CHECK(offerFor5 -> getNumber() == 4);
    }

    SECTION("choosing offers- both types of clients"){
        AllOffers offers;
        offers.addOffer(1, "specjalna 1", "Kup 2 w 1", 10, 2);
        offers.addOffer(2, "specjalna 1", "Kup 2 w 1", 20, 1);
        offers.addOffer(3, "specjalna 1", "Kup 2 w 1", 30, 1);
        offers.addOffer(4, "specjalna 1", "Kup 2 w 1", 40, 1);
        offers.addOffer(5, "specjalna 1", "Kup 2 w 1", 50, 2);

        PrivateClient client1(1, "Kamila");
        PrivateClient client2(2, "Kamil");
        PrivateClient client3(3, "Kamilek");
        BusinessClient client4(4, "Kamil");
        BusinessClient client5(5, "Kamil");
        BusinessClient client6(6, "Mariola");

        shared_ptr<Offer> offerFor1 = client1.chooseOffer(offers);
        shared_ptr<Offer> offerFor2 = client2.chooseOffer(offers);
        shared_ptr<Offer> offerFor3 = client3.chooseOffer(offers);
        shared_ptr<Offer> offerFor4 = client4.chooseOffer(offers);
        shared_ptr<Offer> offerFor5 = client5.chooseOffer(offers);
        shared_ptr<Offer> offerFor6 = client6.chooseOffer(offers);

        CHECK(offerFor1 -> getNumber() == 1);
        CHECK(offerFor2 -> getNumber() == 1);
        CHECK(offerFor3 -> getNumber() == 2);
        CHECK(offerFor4 -> getNumber() == 5);
        CHECK(offerFor5 -> getNumber() == 5);
        CHECK(offerFor6 -> getNumber() == 4);
    }

    SECTION("choosing offers for privateClient- no available offer"){
        AllOffers offers;
        offers.addOffer(1, "specjalna 1", "Kup 2 w 1", 35, 1);

        PrivateClient client1(1, "Kamila");
        PrivateClient client2(2, "Kamil");

        shared_ptr<Offer> offerFor1 = client1.chooseOffer(offers);
        CHECK_THROWS_AS(client2.chooseOffer(offers), NoAvailableOfferException);
    }
    SECTION("choosing offers for businessClient- no available offer"){
        AllOffers offers;
        offers.addOffer(1, "specjalna 1", "Kup 2 w 1", 35, 1);

        BusinessClient client1(1, "Kamila");
        BusinessClient client2(2, "Kamil");

        shared_ptr<Offer> offerFor1 = client1.chooseOffer(offers);
        CHECK_THROWS_AS(client2.chooseOffer(offers), NoAvailableOfferException);
    }
    SECTION("AllClients- adding clients"){
        AllClients clients;
        clients.addPrivateClient(1, "Karol");
        clients.addPrivateClient(2, "Karolina");

        clients.addBusinessClient(3, "Karola");
        clients.addBusinessClient(4, "Konrad");

        CHECK(clients.getNumberOfClients() == 4);
    }
    SECTION("AllClients- removing clients"){
        AllClients clients;
        clients.addPrivateClient(1, "Karol");
        clients.addPrivateClient(2, "Karolina");

        clients.removeClient(1);
        CHECK(clients.getNumberOfClients() == 1);
    }
    SECTION("AllClients- removing clients, wrong number"){
        AllClients clients;
        clients.addPrivateClient(1, "Karol");
        CHECK_THROWS_AS( clients.removeClient(10), NoSuchClientInDatabaseException);
    }
    SECTION("AllClients- adding clients, wrong number"){
        AllClients clients;
        clients.addPrivateClient(1, "Karol");
        CHECK_THROWS_AS( clients.addPrivateClient(1, "Karolina"), ClientInDatabaseException);
    }
    SECTION("AllClients- checking if client in database"){
        AllClients clients;
        clients.addPrivateClient(1, "Karol");
        clients.addPrivateClient(2, "Karolina");

        CHECK(clients.checkClientNumber(1) == 1);
        CHECK(clients.checkClientNumber(2) == 1);
        CHECK(clients.checkClientNumber(3) == 0);
    }
    SECTION("AllOffers- adding and removing offers"){
        AllOffers offers;
        offers.addOffer(1, "2w1", "dwa kredyty w cenie 1", 10, 2);
        offers.addOffer(2, "2w1", "dwa kredyty w cenie 1", 20, 2);
        offers.addOffer(3, "2w1", "dwa kredyty w cenie 1", 30, 2);

        CHECK(offers.getNumberOfOffers() == 3);

        offers.removeOffer(1);
        CHECK(offers.getNumberOfOffers() == 2);
    }
    SECTION("AllWorkers- adding and removing workers"){
        AllWorkers workers;

        workers.addWorker(1, "Kamil", 10);
        workers.addWorker(2, "Kamil", 10);
        workers.addWorker(3, "Kamil", 10);
        workers.addWorker(4, "Kamil", 10);
        workers.addWorker(5, "Kamil", 10);

        CHECK(workers.getNumberOfWorkers() == 5);
        workers.removeWorker(4);
        CHECK(workers.getNumberOfWorkers() == 4);
    }
    SECTION("AllOffers- adding already existing offer"){
        AllOffers offers;
        offers.addOffer(3, "2w1", "dwa kredyty w cenie 1", 30, 2);
        CHECK_THROWS_AS(offers.addOffer(3, "2w1", "dwa kredyty w cenie 1", 30, 2), OfferAlreadyExistsException);
    }
    SECTION("AllWorkers- adding already existing worker"){
        AllWorkers workers;
        workers.addWorker(5, "Kamil", 10);
        CHECK_THROWS_AS(workers.addWorker(5, "Kamil", 10), WorkerAlreadyExistsException);
    }
    SECTION("AllOffers- removing not existing offer"){
        AllOffers offers;
        offers.addOffer(3, "2w1", "dwa kredyty w cenie 1", 30, 2);
        CHECK_THROWS_AS( offers.removeOffer(1), NoSuchOfferException);
    }
    SECTION("AllWorkers- removing not existing worker"){
        AllWorkers workers;
        workers.addWorker(1, "Kamil", 10);
        CHECK_THROWS_AS( workers.removeWorker(10), NoSuchWorkerException);
    }
}