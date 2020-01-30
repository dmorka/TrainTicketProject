#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include "TicketRepository.h"
#include "ClientManager.h"
#include "TicketManager.h"
#include "TrainManager.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientParameterExceptionCase)
    {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        localDateTimePtr birthday1 = nullptr;

        BOOST_REQUIRE_THROW(ClientPtr client(new Client("", "Tadek", "Winkowski", birthday)),ParameterException);
        BOOST_REQUIRE_THROW(ClientPtr client(new Client("12312321", "", "Winkowski", birthday)),ParameterException);
        BOOST_REQUIRE_THROW(ClientPtr client(new Client("123123123", "Tadek", "", birthday)),ParameterException);
        BOOST_REQUIRE_THROW(ClientPtr client(new Client("", "Tadek", "Winkowski", birthday)),ParameterException);
        BOOST_REQUIRE_THROW(ClientPtr client(new Client("12312", "Tadek", "Winkowski", birthday1)),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(TicketParameterExceptionCase)
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

        BOOST_REQUIRE_THROW(TicketPtr ticket(new Ticket(FirstClass, nullptr, train, route, 0.2, startTime, endTime)),ParameterException);
        BOOST_REQUIRE_THROW(TicketPtr ticket(new Ticket(FirstClass, client, nullptr, route, 0.2, startTime, endTime)),ParameterException);
        BOOST_REQUIRE_THROW(TicketPtr ticket(new Ticket(FirstClass, client, train, nullptr, 0.2, startTime, endTime)),ParameterException);
        BOOST_REQUIRE_THROW(TicketPtr ticket(new Ticket(FirstClass, client, train, route, -1, startTime, endTime)),ParameterException);
        BOOST_REQUIRE_THROW(TicketPtr ticket(new Ticket(FirstClass, client, train, route, 1, nullptr, endTime)),ParameterException);
        BOOST_REQUIRE_THROW(TicketPtr ticket(new Ticket(FirstClass, client, train, route, 1, startTime, nullptr)),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(TrainParameterExceptionCase)
    {
        vector<CarriagePtr> wagony;
        CarriagePtr carriage(new Carriage(32, SecondClass));
        CarriagePtr carriage1(new Carriage(32, SecondClass));
        wagony.push_back(carriage);
        wagony.push_back(carriage1);

        BOOST_REQUIRE_THROW(TrainPtr train(new Train(123, "Mickiewicz", wagony)),ParameterException);
        BOOST_REQUIRE_THROW(TrainPtr train(new Train(1233, "", wagony)),ParameterException);

        vector<CarriagePtr> wagony1;
        BOOST_REQUIRE_THROW(TrainPtr train(new Train(1233, "Mickiewicz", wagony1)),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(CarriageParameterExceptionCase)
    {
        BOOST_REQUIRE_THROW(CarriagePtr carriage(new Carriage(20,FirstClass)),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(RouteParameterExceptionCase)
    {
        BOOST_REQUIRE_THROW(RoutePtr route(new Route(0,"Lodz","Warszawa")),ParameterException);
        BOOST_REQUIRE_THROW(RoutePtr route(new Route(120,"","Warszawa")),ParameterException);
        BOOST_REQUIRE_THROW(RoutePtr route(new Route(120,"Lodz","")),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(TimetableParameterExceptionCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        RoutePtr route(new Route(120,"Lodz","Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3,zone));

        BOOST_REQUIRE_THROW(TimetablePtr timetable(new Timetable(nullptr,route,start,end)),ParameterException);
        BOOST_REQUIRE_THROW(TimetablePtr timetable(new Timetable(train,nullptr,start,end)),ParameterException);
        BOOST_REQUIRE_THROW(TimetablePtr timetable(new Timetable(train,route,nullptr,end)),ParameterException);
        BOOST_REQUIRE_THROW(TimetablePtr timetable(new Timetable(train,route,start,nullptr)),ParameterException);
    }

    BOOST_AUTO_TEST_CASE(ManagersParameterExceptionCase)
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
        TicketPtr ticket(new Ticket(FirstClass, client, train, route, 0.2, startTime, endTime));
        TicketRepositoryPtr ticketRep(new TicketRepository());
        ticketRep->create(ticket);

        BOOST_REQUIRE_THROW(ClientManagerPtr cm(new ClientManager(nullptr)),ParameterException);
        BOOST_REQUIRE_THROW(TicketManagerPtr tm(new TicketManager(ticketRep,nullptr)),ParameterException);
        BOOST_REQUIRE_THROW(TrainManagerPtr tm(new TrainManager(nullptr)),ParameterException);
    }

BOOST_AUTO_TEST_SUITE_END()