#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Timetable.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TimetableIDCase)
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
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_REQUIRE_GT(timetable->getID().size(),0);
    }

    BOOST_AUTO_TEST_CASE(TimetableGetTrainCase)
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
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_REQUIRE_EQUAL(timetable->getTrain(), train);
    }

    BOOST_AUTO_TEST_CASE(TimetableGetRouteCase)
    {
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

        BOOST_REQUIRE_EQUAL(timetable->getRoute(), route);
    }

    BOOST_AUTO_TEST_CASE(TimetableSetTrainCase)
    {
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
        TrainPtr train1(new Train(2343, "Slowacki", wagony));
        timetable->setTrain(train1);

        BOOST_REQUIRE_EQUAL(timetable->getTrain(), train1);
    }

    BOOST_AUTO_TEST_CASE(TimetableSetRouteCase)
    {
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
        RoutePtr route1(new Route(250, "Lodz", "Wroclaw"));
        timetable->setRoute(route1);

        BOOST_REQUIRE_EQUAL(timetable->getRoute(), route1);
    }

    BOOST_AUTO_TEST_CASE(TimetableGetStartTimeCase)
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
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_REQUIRE_EQUAL(timetable->getStartTime(), start);
    }

    BOOST_AUTO_TEST_CASE(TimetableGetEndTimeCase)
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
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_REQUIRE_EQUAL(timetable->getEndTime(), end);
    }

    BOOST_AUTO_TEST_CASE(TimetableSetTimeCase)
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
        TimetablePtr timetable(new Timetable(train,route,start,end));
        ptime pt4{date{2020, 02, 20}, time_duration{10, 34, 00}};
        localDateTimePtr start1 = localDateTimePtr(new local_date_time(pt4,zone));
        ptime pt5{date{2020, 02, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end1 = localDateTimePtr(new local_date_time(pt5,zone));
        timetable->setStartTime(start1);
        timetable->setEndTime(end1);

        BOOST_REQUIRE_EQUAL(timetable->getStartTime(), start1);
        BOOST_REQUIRE_EQUAL(timetable->getEndTime(), end1);
    }

    BOOST_AUTO_TEST_CASE(TimetableGetDurationCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        RoutePtr route(new Route(120,"Lodz","Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 32, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3,zone));
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_REQUIRE_CLOSE(timetable->getDuration(), 1.36,0.01);
    }

    BOOST_AUTO_TEST_CASE(TimetableGetInfoCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(53,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        RoutePtr route(new Route(120,"Lodz","Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 32, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3,zone));
        TimetablePtr timetable(new Timetable(train,route,start,end));

        BOOST_TEST_MESSAGE(timetable->getInfo());
    }

    BOOST_AUTO_TEST_CASE(TimetableEqualityOperatorsCase)
    {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(53,FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32,SecondClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        RoutePtr route(new Route(120,"Lodz","Warszawa"));
        RoutePtr route2(new Route(120,"Lodz","Warszawa"));
        RoutePtr route3(new Route(300,"Wrocław","Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2,zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 32, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3,zone));
        TimetablePtr timetable(new Timetable(train,route,start,end));
        TimetablePtr timetable2 = timetable;
        TimetablePtr timetable3(new Timetable(train,route3,start,end));

        BOOST_REQUIRE_EQUAL(*timetable == *timetable2, true);
        BOOST_REQUIRE_EQUAL(*timetable == *timetable3, false);
        BOOST_REQUIRE_EQUAL(*timetable != *timetable3, true);
        BOOST_REQUIRE_EQUAL(*timetable != *timetable2, false);
    }

BOOST_AUTO_TEST_SUITE_END()