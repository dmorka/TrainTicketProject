#include <boost/test/unit_test.hpp>
#include "Ticket.h"
#include <boost/date_time/gregorian/gregorian.hpp>

TicketPtr createTicket();

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TicketPriceCase)
    {
        TicketPtr ticket = createTicket();

        BOOST_REQUIRE_EQUAL(ticket->getPrice(),90);
    }

    BOOST_AUTO_TEST_CASE(TicketDateOfPurchaseCase)
    {
        TicketPtr ticket = createTicket();
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        localDateTimePtr dateOfPurchase = localDateTimePtr(new local_date_time(local_sec_clock::local_time(zone)));

        BOOST_REQUIRE_EQUAL(*ticket->getDateOfPurchase(),*dateOfPurchase);
    }

    BOOST_AUTO_TEST_CASE(TicketIDCase)
    {
        TicketPtr ticket = createTicket();
        BOOST_REQUIRE_GT(ticket->getID().size(),0);
    }

    BOOST_AUTO_TEST_CASE(TicketSeatCase)
    {
        TicketPtr ticket = createTicket();

        BOOST_REQUIRE_EQUAL(ticket->getSeat(),0);
    }

    BOOST_AUTO_TEST_CASE(TicketStartTimeCase)
    {
        TicketPtr ticket = createTicket();
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        ptime pt3{date{2020, 02, 12}, time_duration{10, 55, 00}};
        localDateTimePtr startTime = localDateTimePtr(new local_date_time(pt3,zone));

        BOOST_REQUIRE_EQUAL(*ticket->getStartTime(),*startTime);
    }

    BOOST_AUTO_TEST_CASE(TicketEndTimeCase)
    {
        TicketPtr ticket = createTicket();
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        ptime pt4{date{2020, 02, 12}, time_duration{12, 35, 00}};
        localDateTimePtr endTime = localDateTimePtr(new local_date_time(pt4,zone));

        BOOST_REQUIRE_EQUAL(*ticket->getEndTime(),*endTime);
    }

    BOOST_AUTO_TEST_CASE(TicketClassCase)
    {
        TicketPtr ticket = createTicket();

        BOOST_REQUIRE_EQUAL(ticket->getTicketClass(),FirstClass);

        ticket->setTicketClass(SecondClass);
        BOOST_REQUIRE_EQUAL(ticket->getTicketClass(),SecondClass);
    }

    BOOST_AUTO_TEST_CASE(TicketInfoCase)
    {
        TicketPtr ticket = createTicket();

        BOOST_TEST_MESSAGE(ticket->getInfo(false));
    }

    BOOST_AUTO_TEST_CASE(TicketEqualityOperatorsCase)
    {
        TicketPtr ticket = createTicket();
        TicketPtr ticket2 = ticket;
        TicketPtr ticket3 = createTicket();

        ticket3->setTicketClass(SecondClass);

        BOOST_REQUIRE_EQUAL(*ticket == *ticket2,true);
        BOOST_REQUIRE_EQUAL(*ticket == *ticket3,false);
        BOOST_REQUIRE_EQUAL(*ticket != *ticket3,true);
        BOOST_REQUIRE_EQUAL(*ticket != *ticket2,false);
    }

BOOST_AUTO_TEST_SUITE_END()

TicketPtr createTicket()
{
    time_zone_ptr zone(new posix_time_zone("CET+1"));
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
    return t1;
}