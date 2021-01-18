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

BOOST_AUTO_TEST_CASE(test_rsort)
{
    auto ip_pool = std::vector<IP>{
        IP{222, 173, 235, 64},
        IP{1, 70, 44, 170},
        IP{1, 1, 234, 8},
        IP{222, 82, 198, 61},
        IP{1, 70, 168, 152},
        IP{222, 173, 235, 246}
    };

    rsort_lexicographically(ip_pool.begin(), ip_pool.end());
    auto res = std::vector<IP>{
        IP{222, 173, 235, 246},
        IP{222, 173, 235, 64},
        IP{222, 82, 198, 61},
        IP{1, 70, 168, 152},
        IP{1, 70, 44, 170},
        IP{1, 1, 234, 8}
    };

    BOOST_CHECK(ip_pool == res);
}

BOOST_AUTO_TEST_SUITE_END()