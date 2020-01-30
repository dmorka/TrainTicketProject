#include <boost/test/unit_test.hpp>
#include "ClientManager.h"
#include "ClientRepository.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerCreateClientRemoveClientCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        ClientManagerPtr cm(new ClientManager(clientRep));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(cm->createClient(client),1);
        BOOST_REQUIRE_EQUAL(cm->removeClient(client),1);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerClientsInfoCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        ClientManagerPtr cm(new ClientManager(clientRep));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(cm->createClient(client),1);
        BOOST_TEST_MESSAGE(cm->getClientsInfo());
    }

BOOST_AUTO_TEST_SUITE_END()