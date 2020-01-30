#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientRepositoryCreateRemoveCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890", "Tadek", "Winkowski", birthday));
        ClientPtr client2(new Client("0987654321", "Wladek", "Kilinski", birthday));

        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(clientRep->create(client), 1);
        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(clientRep->getElement(0)->getID(), client->getID());
        BOOST_REQUIRE_EQUAL(clientRep->remove(client), 1);
        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(clientRep->create(client2), 1);
        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(clientRep->remove(0), 1);
        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),0);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryInfoCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890", "Tadek", "Winkowski", birthday));

        BOOST_REQUIRE_EQUAL(clientRep->create(client), 1);
        BOOST_TEST_MESSAGE(clientRep->getInfo());
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890", "Tadek", "Winkowski", birthday));
        ClientPtr client2(new Client("0987654321", "Wladek", "Kilinski", birthday));

        BOOST_REQUIRE_EQUAL(clientRep->create(client), 1);
        BOOST_REQUIRE_EQUAL(clientRep->create(client2), 1);
        BOOST_REQUIRE_EQUAL(clientRep->find("0987654321")->getID(), client2->getID());
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryClearCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890", "Tadek", "Winkowski", birthday));
        ClientPtr client2(new Client("0987654321", "Wladek", "Kilinski", birthday));

        BOOST_REQUIRE_EQUAL(clientRep->create(client), 1);
        BOOST_REQUIRE_EQUAL(clientRep->create(client2), 1);
        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),2);
        BOOST_REQUIRE_EQUAL(clientRep->clear(), 1);
        BOOST_REQUIRE_EQUAL(clientRep->getElements().size(),0);
    }

BOOST_AUTO_TEST_SUITE_END()