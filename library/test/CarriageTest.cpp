#include <boost/test/unit_test.hpp>
#include "Carriage.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CarriageNumberOfSeatsCase)
    {
        CarriagePtr carriage(new Carriage(50,FirstClass));

        BOOST_REQUIRE_EQUAL(carriage->getNumberOfSeats(),50);
    }

    BOOST_AUTO_TEST_CASE(CarriageTravelClassCase)
    {
        CarriagePtr carriage(new Carriage(50,FirstClass));

        BOOST_REQUIRE_EQUAL(carriage->getCarriageClass(),FirstClass);
    }

    BOOST_AUTO_TEST_CASE(CarriageGetInfoCase)
    {
        CarriagePtr carriage(new Carriage(50,FirstClass));

        BOOST_TEST_MESSAGE(carriage->getInfo());
    }

    BOOST_AUTO_TEST_CASE(CarriageGetSetFreeSeatCase)
    {
        CarriagePtr carriage(new Carriage(50,FirstClass));
        carriage->setFreeSeat(10,1);

        BOOST_REQUIRE_EQUAL(carriage->getFreeSeats()[10],true);
    }

    BOOST_AUTO_TEST_CASE(CarriageEqualityOperationsCase)
    {
        CarriagePtr carriage(new Carriage(50,FirstClass));
        CarriagePtr carriage2(new Carriage(50,FirstClass));
        CarriagePtr carriage3(new Carriage(40,FirstClass));

        BOOST_REQUIRE_EQUAL(*carriage==*carriage2,true);
        BOOST_REQUIRE_EQUAL(*carriage==*carriage3,false);
        BOOST_REQUIRE_EQUAL(*carriage!=*carriage3,true);
        BOOST_REQUIRE_EQUAL(*carriage!=*carriage2,false);
    }

BOOST_AUTO_TEST_SUITE_END()