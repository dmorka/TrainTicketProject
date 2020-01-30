#include <boost/test/unit_test.hpp>
#include "TrainRepository.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TrainRepositoryCreateRemoveCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        TrainPtr train1(new Train(2344,"Slowacki",wagony));

        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(trainRep->create(train), 1);
        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(trainRep->getElement(0)->getID(), train->getID());
        BOOST_REQUIRE_EQUAL(trainRep->remove(train), 1);
        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(trainRep->create(train1), 1);
        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(trainRep->remove(0), 1);
        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),0);
    }

    BOOST_AUTO_TEST_CASE(TrainRepositoryInfoCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(trainRep->create(train), 1);
        BOOST_TEST_MESSAGE(trainRep->getInfo());
    }

    BOOST_AUTO_TEST_CASE(TrainRepositoryFindCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        TrainPtr train1(new Train(2344,"Slowacki",wagony));

        BOOST_REQUIRE_EQUAL(trainRep->create(train), 1);
        BOOST_REQUIRE_EQUAL(trainRep->create(train1), 1);
        BOOST_REQUIRE_EQUAL(trainRep->find("2344")->getID(), train1->getID());
    }

    BOOST_AUTO_TEST_CASE(TrainRepositoryClearCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        TrainPtr train1(new Train(2334,"Slowacki",wagony));

        BOOST_REQUIRE_EQUAL(trainRep->create(train), 1);
        BOOST_REQUIRE_EQUAL(trainRep->create(train1), 1);
        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),2);
        BOOST_REQUIRE_EQUAL(trainRep->clear(), 1);
        BOOST_REQUIRE_EQUAL(trainRep->getElements().size(),0);
    }

BOOST_AUTO_TEST_SUITE_END()