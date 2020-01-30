#include <boost/test/unit_test.hpp>
#include "TrainManager.h"
#include "TrainRepository.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TrainManagerCreateRemoveTrainCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        TrainManagerPtr tm(new TrainManager(trainRep));
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(tm->createTrain(train),1);
        BOOST_REQUIRE_EQUAL(tm->removeTrain(train),1);
    }

    BOOST_AUTO_TEST_CASE(TrainManagerClientsInfoCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        TrainManagerPtr tm(new TrainManager(trainRep));
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(tm->createTrain(train),1);
        BOOST_TEST_MESSAGE(tm->getTrainsInfo());
    }

BOOST_AUTO_TEST_SUITE_END()