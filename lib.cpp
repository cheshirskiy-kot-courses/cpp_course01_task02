#include "lib.h"

#include <algorithm>


std::vector<std::string> split(const std::string & str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}


IP parse_ip(const std::string & str)
{
    auto ip = split(split(str, '\t').at(0), '.');

    IP ip_uint8;
    int i = 0;
    for (auto ip_part : ip) {
        ip_uint8[i] = (static_cast<uint8_t>(std::stoul(ip_part)));
        i++;
    }

    return ip_uint8;
}


void rsort_lexicographically(IP_Iter first, IP_Iter last)
{
    std::sort(first, last, std::greater<IP>());
}
