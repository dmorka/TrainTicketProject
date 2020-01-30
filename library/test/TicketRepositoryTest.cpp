#include <boost/test/unit_test.hpp>
#include "TicketRepository.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

void createTickets(TicketPtr &t1, TicketPtr &t2);

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ticketRepositoryCreateRemoveCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
        TicketPtr t1;
        TicketPtr t2;
        createTickets(t1,t2);

        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(ticketRep->create(t1), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElement(0)->getID(), t1->getID());
        BOOST_REQUIRE_EQUAL(ticketRep->remove(t1), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(ticketRep->create(t2), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(ticketRep->remove(0), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),0);
    }

    BOOST_AUTO_TEST_CASE(ticketRepositoryInfoCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
        TicketPtr t1;
        TicketPtr t2;
        createTickets(t1,t2);

        BOOST_REQUIRE_EQUAL(ticketRep->create(t1), 1);
        BOOST_TEST_MESSAGE(ticketRep->getInfo());
    }

    BOOST_AUTO_TEST_CASE(ticketRepositoryFindCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
        TicketPtr t1;
        TicketPtr t2;
        createTickets(t1,t2);

        BOOST_REQUIRE_EQUAL(ticketRep->create(t1), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->create(t2), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->find(to_string(t2->getID()))->getID(), t2->getID());
    }

    BOOST_AUTO_TEST_CASE(ticketRepositoryClearCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
        TicketPtr t1;
        TicketPtr t2;
        createTickets(t1,t2);

        BOOST_REQUIRE_EQUAL(ticketRep->create(t1), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->create(t2), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),2);
        BOOST_REQUIRE_EQUAL(ticketRep->clear(), 1);
        BOOST_REQUIRE_EQUAL(ticketRep->getElements().size(),0);
    }

BOOST_AUTO_TEST_SUITE_END()

void createTickets(TicketPtr &t1, TicketPtr &t2)
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
    TicketPtr tn1(new Ticket(FirstClass, client, train, route, 0.2, startTime, endTime));
    TicketPtr tn2(new Ticket(SecondClass, client, train, route, 0.2, startTime, endTime));
    t1 = tn1;
    t2 = tn2;
}