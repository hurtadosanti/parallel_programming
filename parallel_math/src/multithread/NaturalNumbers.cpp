//
// Created by Santiago Hurtado on 18.10.19.
//

#include "multithread/NaturalNumbers.h"

namespace multithread{
    double NaturalNumbers::calculate_sum_primes(size_t size) {
        this->result.clear();
        double result = 0;
        boost::asio::thread_pool pool(std::thread::hardware_concurrency());
        boost::lockfree::queue<unsigned int> results(size);
        for (auto i = 0; i < size; i++) {
            boost::asio::post(pool, [&results, i]() {
                if (is_prime(i)) {
                    results.push(i);
                }
            });
        }
        pool.join();
        unsigned int value;
        while (results.pop(value)) {
            result += value;
            this->result.push_back(value);
        }
        return result;
    }
    bool NaturalNumbers::is_prime(unsigned int number) {
        if (number == 2) {
            return true;
        } else if (number < 2 || number % 2 == 0) {
            return false;
        } else {
            // A faster option is to use math sqr root
            for (auto i = 2; i < number / 2; ++i) {
                if (number % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }
}