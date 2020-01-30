#include <boost/test/unit_test.hpp>
#include "TimetableRepository.h"
#include <string>

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(TimetableRepositoryCreateRemoveCase)
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
        vector<CarriagePtr> wagony1;
        wagony1.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony1.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train1(new Train(1233, "Mickiewicz", wagony));
        RoutePtr route1(new Route(120, "Lodz", "Warszawa"));
        time_zone_ptr zone1(new posix_time_zone("CET"));
        ptime pt21{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start1 = localDateTimePtr(new local_date_time(pt21, zone));
        ptime pt31{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end1 = localDateTimePtr(new local_date_time(pt31, zone));
        TimetablePtr timetable1(new Timetable(train1, route1, start1, end1));

        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElement(0)->getID(), timetable->getID());
        BOOST_REQUIRE_EQUAL(timetableRep->remove(timetable), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),0);
        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable1), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),1);
        BOOST_REQUIRE_EQUAL(timetableRep->remove(0), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),0);
    }

    BOOST_AUTO_TEST_CASE(TimetableRepositoryInfoCase)
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

        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable), 1);
        BOOST_TEST_MESSAGE(timetableRep->getInfo());
    }

    BOOST_AUTO_TEST_CASE(TimetableRepositoryFindCase)
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
        vector<CarriagePtr> wagony1;
        wagony1.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony1.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train1(new Train(1233, "Mickiewicz", wagony));
        RoutePtr route1(new Route(120, "Lodz", "Warszawa"));
        time_zone_ptr zone1(new posix_time_zone("CET"));
        ptime pt21{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start1 = localDateTimePtr(new local_date_time(pt21, zone));
        ptime pt31{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end1 = localDateTimePtr(new local_date_time(pt31, zone));
        TimetablePtr timetable1(new Timetable(train1, route1, start1, end1));

        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable1), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->find(to_string(timetable1->getID()))->getID(),timetable1->getID());
    }

    BOOST_AUTO_TEST_CASE(TimetableRepositoryClearCase)
    {
        TimetableRepositoryPtr timetableRep(new TimetableRepository());
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train(new Train(1243, "Mickiewicz", wagony));
        RoutePtr route(new Route(120, "Lodz", "Warszawa"));
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start = localDateTimePtr(new local_date_time(pt2, zone));
        ptime pt3{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end = localDateTimePtr(new local_date_time(pt3, zone));
        TimetablePtr timetable(new Timetable(train, route, start, end));
        vector<CarriagePtr> wagony1;
        wagony1.push_back(CarriagePtr(new Carriage(43, FirstClass)));
        wagony1.push_back(CarriagePtr(new Carriage(32, SecondClass)));
        TrainPtr train1(new Train(1234, "Mickiewicz", wagony));
        RoutePtr route1(new Route(120, "Lodz", "Warszawa"));
        time_zone_ptr zone1(new posix_time_zone("CET"));
        ptime pt21{date{2020, 01, 20}, time_duration{10, 56, 00}};
        localDateTimePtr start1 = localDateTimePtr(new local_date_time(pt21, zone));
        ptime pt31{date{2020, 01, 20}, time_duration{12, 34, 00}};
        localDateTimePtr end1 = localDateTimePtr(new local_date_time(pt31, zone));
        TimetablePtr timetable1(new Timetable(train1, route1, start1, end1));

        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->create(timetable1), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),2);
        BOOST_REQUIRE_EQUAL(timetableRep->clear(), 1);
        BOOST_REQUIRE_EQUAL(timetableRep->getElements().size(),0);
    }

BOOST_AUTO_TEST_SUITE_END()