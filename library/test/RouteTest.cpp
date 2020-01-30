#include <boost/test/unit_test.hpp>
#include "Route.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RouteLengthCase)
    {
        RoutePtr route(new Route(120,"Lodz","Warszawa"));

        BOOST_REQUIRE_EQUAL(route->getLength(), 120);
    }

    BOOST_AUTO_TEST_CASE(RouteStartPointCase)
    {
        RoutePtr route(new Route(120,"Lodz","Warszawa"));

        BOOST_REQUIRE_EQUAL(route->getStartPoint(), "Lodz");
    }

    BOOST_AUTO_TEST_CASE(RouteEndPointCase)
    {
        RoutePtr route(new Route(120,"Lodz","Warszawa"));

        BOOST_REQUIRE_EQUAL(route->getEndPoint(), "Warszawa");
    }

    BOOST_AUTO_TEST_CASE(RouteGetInfoCase)
    {
        RoutePtr route(new Route(120,"Lodz","Warszawa"));

        BOOST_TEST_MESSAGE(route->getInfo());
    }

    BOOST_AUTO_TEST_CASE(RouteEqulityOperatorsCase)
    {
        RoutePtr route(new Route(120,"Lodz","Warszawa"));
        RoutePtr route2(new Route(120,"Lodz","Warszawa"));
        RoutePtr route3(new Route(300,"Wroclaw","Warszawa"));

        BOOST_REQUIRE_EQUAL(*route==*route2, true);
        BOOST_REQUIRE_EQUAL(*route==*route3, false);
        BOOST_REQUIRE_EQUAL(*route!=*route3, true);
        BOOST_REQUIRE_EQUAL(*route!=*route2, false);
    }

BOOST_AUTO_TEST_SUITE_END()