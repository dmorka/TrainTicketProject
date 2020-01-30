#include <boost/test/unit_test.hpp>
#include "Train.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TrainIDCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(train->getID(), 1233);
    }

    BOOST_AUTO_TEST_CASE(TrainNameCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(train->getName(), "Mickiewicz");
    }

    BOOST_AUTO_TEST_CASE(TrainGetCarriagesCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(train->getCarriages().size(), 2);

        CarriagePtr carriage(new Carriage(30,SecondClass));

        train->addCarriage(carriage);
        BOOST_REQUIRE_EQUAL(train->getCarriages().size(), 3);

        train->removeCarriage(1);
        BOOST_REQUIRE_EQUAL(train->getCarriages().size(), 2);

        train->removeCarriage(carriage);
        BOOST_REQUIRE_EQUAL(train->getCarriages().size(), 1);
    }

    BOOST_AUTO_TEST_CASE(TrainGetCarriageCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(train->getCarriage(0)->getNumberOfSeats(), 43);
    }

    BOOST_AUTO_TEST_CASE(TrainBookSeatCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train(new Train(1233, "Mickiewicz", wagony));
        train->bookSeat(SecondClass);

        BOOST_REQUIRE_EQUAL(train->getCarriage(1)->getFreeSeats()[0], true);
    }

    BOOST_AUTO_TEST_CASE(TrainGetInfoCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train(new Train(1233, "Mickiewicz", wagony));

        BOOST_TEST_MESSAGE(train->getInfo());
    }

    BOOST_AUTO_TEST_CASE(TrainEqualityOperatorsCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train(new Train(1233, "Mickiewicz", wagony));
        vector<CarriagePtr> wagony2;
        wagony2.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony2.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train2(new Train(1233, "Mickiewicz", wagony2));
        TrainPtr train3(new Train(1233, "Wincenty", wagony));

        BOOST_REQUIRE_EQUAL(*train == *train2, true);
        BOOST_REQUIRE_EQUAL(*train == *train3, false);
        BOOST_REQUIRE_EQUAL(*train != *train3, true);
        BOOST_REQUIRE_EQUAL(*train != *train2, false);
    }

BOOST_AUTO_TEST_SUITE_END()