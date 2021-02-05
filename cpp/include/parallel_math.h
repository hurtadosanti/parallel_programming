//
// Created by SHurtado on 2/1/2021.
//

#ifndef PARALLEL_PROGRAMMING_PARALLEL_MATH_H
#define PARALLEL_PROGRAMMING_PARALLEL_MATH_H
#include <vector>
#include <thread>
#include <iostream>
#include <atomic>
#include <cmath>
namespace Samples {
    class ParallelMath {
    public:
        static bool is_prime(int number);

        static unsigned int calculate_sum_primes(const size_t size);

        static void matrix_multiply(long ** A, size_t num_rows_a, size_t num_cols_a,
                                    long ** B, size_t num_rows_b, size_t num_cols_b,
                                    long ** C);
    };
}

#endif //PARALLEL_PROGRAMMING_PARALLEL_MATH_H
