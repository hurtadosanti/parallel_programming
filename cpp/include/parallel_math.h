//
// Created by SHurtado on 2/1/2021.
//

#ifndef PARALLEL_PROGRAMMING_PARALLEL_MATH_H
#define PARALLEL_PROGRAMMING_PARALLEL_MATH_H
#include <vector>
#include <thread>
#include <iostream>
#include <atomic>
namespace Samples {
    class ParallelMath {
    private:
        std::vector<unsigned int> result;
    public:

        size_t size() { return result.size(); };

        std::vector<unsigned int>::iterator begin() { return result.begin(); };

        std::vector<unsigned int>::iterator end() { return result.end(); };

        unsigned int get(size_t position);

        static bool is_prime(int number);

        unsigned int calculate_sum_primes(const size_t size);

        unsigned int calculate_sum_primes_sl(const size_t size);

        void sum(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b);
    };
}

#endif //PARALLEL_PROGRAMMING_PARALLEL_MATH_H
