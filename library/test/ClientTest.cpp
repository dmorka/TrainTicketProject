#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "Ticket.h"
#include "Train.h"
#include "Route.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

TicketPtr createTicket();

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientPersonalIDCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(client->getID(), "1234567890");
    }

    BOOST_AUTO_TEST_CASE(ClientFirstNameCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(client->getFirstName(), "Jan");
    }

    BOOST_AUTO_TEST_CASE(ClientLastNameCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(client->getLastName(), "Kowalski");
    }

    BOOST_AUTO_TEST_CASE(ClientDateOfBirthCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(client->getDateOfBirth(), birthday);
    }

    BOOST_AUTO_TEST_CASE(ClientAgeCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 01, 01}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(client->getAge(), 30);
    }

    BOOST_AUTO_TEST_CASE(ClientTicketsCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 01, 01}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{2020, 02, 12}, time_duration{10, 55, 00}};
        localDateTimePtr startTime = localDateTimePtr(new local_date_time(pt3,zone));
        ptime pt4{date{2020, 02, 12}, time_duration{12, 35, 00}};
        localDateTimePtr endTime = localDateTimePtr(new local_date_time(pt4,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));
        vector<CarriagePtr> carriages;
        CarriagePtr c1(new Carriage(100,FirstClass));
        CarriagePtr c2(new Carriage(120,SecondClass));
        carriages.push_back(c1);
        carriages.push_back(c2);
        TrainPtr train(new Train(124221,"Pociag",carriages));
        RoutePtr route(new Route(300,"Wroclaw", "Lodz"));
        TicketPtr t1(new Ticket(FirstClass, client, train, route, 0.2, startTime, endTime));
        TicketPtr t2(new Ticket(SecondClass, client, train, route, 0.2, startTime, endTime));

        BOOST_REQUIRE_EQUAL(client->getTickets().size(), 0);
        client->addTicket(t1);
        client->addTicket(t2);

        BOOST_REQUIRE_EQUAL(client->getTickets().size(), 2);

        client->removeTicket(t1);

        BOOST_REQUIRE_EQUAL(client->getTickets().size(), 1);
        BOOST_REQUIRE_EQUAL(client->getTickets().at(0), t2);
    }

    BOOST_AUTO_TEST_CASE(ClientInfoCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 01, 01}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_TEST_MESSAGE(client->getInfo(false));
    }

    BOOST_AUTO_TEST_CASE(ClientEqualityOperatorCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 01, 01}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{1990, 01, 01}, time_duration{10, 56, 12}};
        localDateTimePtr birthday2 = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));
        ClientPtr client2(new Client("1234567890","Jan", "Kowalski", birthday2));
        ClientPtr client3(new Client("0987654321","Jan", "Kowalski", birthday));
        TicketPtr t1 = createTicket();
        TicketPtr t2 = t1;
        TicketPtr t3 = createTicket();
        client->addTicket(t1);
        client2->addTicket(t2);
        client3->addTicket(t3);
        BOOST_REQUIRE_EQUAL(*client==*client2,true);
        BOOST_REQUIRE_EQUAL(*client==*client3,false);
        BOOST_REQUIRE_EQUAL(*client!=*client3,true);
        BOOST_REQUIRE_EQUAL(*client!=*client2,false);
    }


BOOST_AUTO_TEST_SUITE_END()