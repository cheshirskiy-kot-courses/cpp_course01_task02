#pragma once

#include <string>
#include <vector>
#include <array>


using IP = std::array<uint8_t, 4>;
using IP_Iter = std::vector<IP>::iterator;


// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string & str, char d);

IP parse_ip(const std::string & str);

void rsort_lexicographically(IP_Iter first, IP_Iter last);
