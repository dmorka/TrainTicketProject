#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include "TicketRepository.h"
#include "TrainRepository.h"
#include "TimetableRepository.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientDuplicateExceptionCase)
    {
        ClientRepositoryPtr clientRep(new ClientRepository());
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890", "Tadek", "Winkowski", birthday));

        BOOST_REQUIRE_EQUAL(clientRep->create(client),1);
        BOOST_REQUIRE_THROW(clientRep->create(client),DuplicateException);
    }

    BOOST_AUTO_TEST_CASE(TicketDuplicateExceptionCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
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

        BOOST_REQUIRE_EQUAL(ticketRep->create(t1),1);
        BOOST_REQUIRE_THROW(ticketRep->create(t1),DuplicateException);
    }

    BOOST_AUTO_TEST_CASE(TrainDuplicateExceptionCase)
    {
        TrainRepositoryPtr trainRep(new TrainRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));

        BOOST_REQUIRE_EQUAL(trainRep->create(train),1);
        BOOST_REQUIRE_THROW(trainRep->create(train),DuplicateException);
    }

    BOOST_AUTO_TEST_CASE(TimetablenDuplicateExceptionCase)
    {
        TimetableRepositoryPtr timetableRep(new TimetableRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train(new Train(1233, "Mickiewicz", wagony));
        RoutePtr route(new Route(120, "Lodz", "Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2, zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3, zone));
        TimetablePtr timetable(new Timetable(train, route, start, end));

        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable),1);
        BOOST_REQUIRE_THROW(timetableRep->create(timetable),DuplicateException);
    }

BOOST_AUTO_TEST_SUITE_END()