#include <cstdlib>
#include <iostream>

#include "lib.h"


int main(int argc, char const * argv[])
{
    try {
        std::vector<IP> ip_pool;

        for (std::string line; std::getline(std::cin, line);) {
            ip_pool.push_back(parse_ip(line));
            break;
        }

        rsort_lexicographically(ip_pool.begin(), ip_pool.end());

        for (auto & ip : ip_pool) {
            std::cout << std::to_string(ip[0]);
            for (int i = 1; i < ip.size() ; i++) {
                std::cout << "." << std::to_string(ip[i]);
            }
            std::cout << std::endl;
        }
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
