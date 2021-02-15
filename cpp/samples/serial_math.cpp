//
// Created by shurtado on 04.02.21.
//
#include <cstdlib>
#include "serial_math.h"

namespace Samples {
    unsigned int SerialMath::calculate_sum_primes(size_t size) {
        auto result = 0;
        for (auto i = 0; i < size; ++i) {
            if (is_prime(i)) {
                result += i;
            }
        }
        return result;
    }

    void SerialMath::matrix_multiply(long **A, size_t num_rows_a, size_t num_cols_a, long **B, size_t num_rows_b,
                                     size_t num_cols_b, long **C) {
        for (size_t i = 0; i < num_rows_a; i++) {
            for (size_t j = 0; j < num_cols_b; j++) {
                C[i][j] = 0; // initialize result cell to zero
                for (size_t k = 0; k < num_cols_a; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    bool SerialMath::is_prime(int number) {
        if (number == 2) {
            return true;
        } else if (number < 2 || number % 2 == 0) {
            return false;
        } else {
            for (int i = 2; i < number / 2; i++) {
                if (number % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    void SerialMath::init_matrix(const size_t size, long **&A, long **&B, long **&result) {
        A= (long **)malloc(size * sizeof(long *));
        B= (long **)malloc(size * sizeof(long *));
        result= (long **)malloc(size * sizeof(long *));
        for (size_t i=0; i<size; i++) {
            A[i] = (long *)malloc(size * sizeof(long));
            if (A[i] == nullptr) {
                exit(2);
            }
            for (size_t j=0; j<size; j++) {
                A[i][j] = 1;
            }
        }
        for (size_t i=0; i<size; i++) {
            B[i] = (long *)malloc(size * sizeof(long));
            if (B[i] == nullptr) {
                exit(2);
            }
            for (size_t j=0; j<size; j++) {
                B[i][j] = 1;
            }
        }
        for (size_t i=0; i<size; i++) {
            result[i] = (long *)malloc(size * sizeof(long));
            if (result[i] == nullptr) {
                exit(2);
            }
        }
    }

    unsigned int SerialMath::sum(std::vector<unsigned int> &values) {
        auto result = 0;
        for(auto &i: values){
            result+=i;
        }
        return result;
    }
}