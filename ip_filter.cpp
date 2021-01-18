#include <cstdlib>
#include <iostream>

#include "lib.h"


void print_pool(const IP_Pool & ip_pool)
{
    for (auto & ip : ip_pool) {
        std::cout << std::to_string(ip[0]);
        for (int i = 1; i < ip.size(); i++) {
            std::cout << "." << std::to_string(ip[i]);
        }
        std::cout << std::endl;
    }
}


int main(int argc, char const * argv[])
{
    try {
        IP_Pool ip_pool;

        for (std::string line; std::getline(std::cin, line);) {
            ip_pool.push_back(parse_ip(line));
        }

        rsort_lexicographically(ip_pool.begin(), ip_pool.end());

        auto ip_pool_1 = filter(ip_pool, 1);
        auto ip_pool_46_70 = filter(ip_pool, 46, 70);
        auto ip_pool_any_46 = filter_any(ip_pool, 46);

        print_pool(ip_pool);
        print_pool(ip_pool_1);
        print_pool(ip_pool_46_70);
        print_pool(ip_pool_any_46);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
