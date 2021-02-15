//
// Created by shurtado on 04.02.21.
//

#ifndef PARALLEL_PROGRAMMING_SERIAL_MATH_H
#define PARALLEL_PROGRAMMING_SERIAL_MATH_H
#include <vector>
namespace Samples {
    class SerialMath {
    public:
        static unsigned int calculate_sum_primes(size_t size);
        static void matrix_multiply(long ** A, size_t num_rows_a, size_t num_cols_a,
                                        long ** B, size_t num_rows_b, size_t num_cols_b,
                                        long ** C);
        static bool is_prime(int number);

        static void init_matrix(const size_t size, long **&A, long **&B,
                                long **&result);

        static unsigned int sum(std::vector<unsigned int> &values);
    };
}
#endif //PARALLEL_PROGRAMMING_SERIAL_MATH_H
