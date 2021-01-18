#define BOOST_TEST_MODULE ip_filter_test_module

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ip_filter_test_suite)

using namespace std;

BOOST_AUTO_TEST_CASE(test_parse_ip)
{
    auto in = "113.162.145.156\t111\t0"s;
    auto out = parse_ip(in);
    auto res = IP{ 113, 162, 145, 156 };
    BOOST_CHECK(out == res);
}

BOOST_AUTO_TEST_SUITE_END()