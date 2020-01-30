#include <boost/test/unit_test.hpp>
#include "Carriage.h"
#include "Client.h"
#include "Ticket.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

//defincja funkcji znajduje sie w pliku TicketTest
TicketPtr createTicket();

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CarriageAvailableExceptionCase) {
        CarriagePtr carriage(new Carriage(50,FirstClass));
        BOOST_REQUIRE_THROW(carriage->setFreeSeat(-1,1),AvailableException);
        BOOST_REQUIRE_THROW(carriage->setFreeSeat(50,1),AvailableException);
    }

    BOOST_AUTO_TEST_CASE(ClientAvailableExceptionCase) {
        time_zone_ptr zone(new posix_time_zone("CET"));
        ptime pt2{date{1990, 12, 21}, time_duration{10, 56, 12}};
        localDateTimePtr birthday = localDateTimePtr(new local_date_time(pt2,zone));
        ClientPtr client(new Client("1234567890","Jan", "Kowalski", birthday));
        TicketPtr ticket = createTicket();
        BOOST_REQUIRE_THROW(client->removeTicket(ticket),AvailableException);
    }

    BOOST_AUTO_TEST_CASE(TrainAvailableExceptionCase) {
        vector<CarriagePtr> wagony;
        wagony.push_back(CarriagePtr(new Carriage(43,FirstClass)));
        TrainPtr train(new Train(1233,"Mickiewicz",wagony));
        BOOST_REQUIRE_THROW(train->bookSeat(SecondClass),AvailableException);
        BOOST_REQUIRE_EQUAL(train->removeCarriage(0), 1);
        BOOST_REQUIRE_THROW(train->bookSeat(FirstClass),AvailableException);
    }

BOOST_AUTO_TEST_SUITE_END()