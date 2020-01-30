#include <boost/test/unit_test.hpp>
#include "TicketManager.h"
#include "TicketRepository.h"
#include <string>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TicketManagerCreateRemoveTimetableCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
        TimetableRepositoryPtr timetableRep(new TimetableRepository());
        TicketManagerPtr tm(new TicketManager(ticketRep,timetableRep));
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(42,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1231,"Mickiewicz",wagony));
        RoutePtr route(new Route(120,"Lodz","Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3,zone));
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_REQUIRE_EQUAL(tm->createTimetable(timetable),1);
        BOOST_REQUIRE_EQUAL(tm->removeTimetable(timetable),1);
    }

    BOOST_AUTO_TEST_CASE(TicketManagerBuyCencelInfoTicketTimetableCase)
    {
        TicketRepositoryPtr ticketRep(new TicketRepository());
        TimetableRepositoryPtr timetableRep(new TimetableRepository());
        TicketManagerPtr tm(new TicketManager(ticketRep, timetableRep));
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train(new Train(1231, "Mickiewicz", wagony));
        RoutePtr route(new Route(120, "Lodz", "Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2, zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3, zone));
        TimetablePtr timetable(new Timetable(train, route, start, end));
        ptime pt4{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));

        BOOST_REQUIRE_EQUAL(tm->buyTicket(client,timetable,SecondClass,0.5),1);
        BOOST_REQUIRE_EQUAL(tm->cancelTicket(ticketRep->getElements().at(0)),1);
        BOOST_REQUIRE_EQUAL(tm->buyTicket(client,timetable,FirstClass,0.5),1);
        BOOST_REQUIRE_EQUAL(client->getTickets().size(), 1);
        BOOST_REQUIRE_EQUAL(tm->createTimetable(timetable),1);
        BOOST_TEST_MESSAGE(tm->getTimetableInfo());
        BOOST_TEST_MESSAGE(tm->getTicketsInfo());
        BOOST_REQUIRE_EQUAL(tm->clearTimetable(),1);
    }

BOOST_AUTO_TEST_SUITE_END()
