#include <iostream>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include <thread>
#include <string>
#include <cmath>

bool is_prime(unsigned int num) {
    if (num == 2) {
        return true;
    } else if (num < 2 || num % 2 == 0) {
        return false;
    } else {
        for (int i = 2; i < num / 2; i++) {
            if (num % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **args) {
    int size = 10;
    double sum = 0;
    if (argc == 2) {
        size = std::stoi(args[1]);
    }

    boost::asio::thread_pool pool(std::thread::hardware_concurrency());
    boost::lockfree::queue<unsigned int> results(size);

    for (unsigned int i = 0; i < size; i++) {
        boost::asio::post(pool, [&results, i]() {
            if (is_prime(i)) {
                results.push(i);
            }
        });
    }
    pool.join();
    unsigned int value;
    while (results.pop(value)) {
        sum += value;
    }
    std::cout << sum << std::endl;
    return 0;
}