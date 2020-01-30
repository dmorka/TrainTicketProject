#include <boost/test/unit_test.hpp>
#include "StudentClient.h"
#include "PensionerClient.h"
#include "BasicClient.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientTypeNameTypeCase)
    {
        StudentClient student;
        BasicClient basic;
        PensionerClient pensioner;

        BOOST_REQUIRE_EQUAL(student.getTypeName(),"Student");
        BOOST_REQUIRE_EQUAL(basic.getTypeName(),"Podstawowy");
        BOOST_REQUIRE_EQUAL(pensioner.getTypeName(),"Senior");
    }

    BOOST_AUTO_TEST_CASE(ClientTypeMaxAgeCase)
    {
        StudentClient student;
        BasicClient basic;
        PensionerClient pensioner;

        BOOST_REQUIRE_EQUAL(student.getMaxAge(),26);
        BOOST_REQUIRE_EQUAL(basic.getMaxAge(),67);
        BOOST_REQUIRE_EQUAL(pensioner.getMaxAge(),150);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeDiscountCase)
    {
        StudentClient student;
        BasicClient basic;
        PensionerClient pensioner;

        BOOST_REQUIRE_EQUAL(student.getDiscount(),0.5);
        BOOST_REQUIRE_EQUAL(basic.getDiscount(),1);
        BOOST_REQUIRE_EQUAL(pensioner.getDiscount(),0.7);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeCountDiscountCase)
    {
        StudentClient student;
        BasicClient basic;
        PensionerClient pensioner;

        BOOST_REQUIRE_CLOSE(student.countDiscount(63.87),31.94,0.01);
        BOOST_REQUIRE_CLOSE(basic.countDiscount(63.87),63.87,0.01);
        BOOST_REQUIRE_CLOSE(pensioner.countDiscount(63.87),44.71,0.01);
    }

BOOST_AUTO_TEST_SUITE_END()