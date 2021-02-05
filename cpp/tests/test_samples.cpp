//
// Created by shurtado on 1/30/2021.
//
#include <gtest/gtest.h>
#include "include/parallel_math.h"
#include "include/serial_math.h"

TEST(MultithreadNaturalNumbers, IsPrime) {

    auto pm = Samples::ParallelMath();

    ASSERT_TRUE(pm.is_prime(2));
    ASSERT_TRUE(pm.is_prime(3));
    ASSERT_TRUE(pm.is_prime(71));
    ASSERT_TRUE(pm.is_prime(7919));
}

TEST(MultithreadNaturalNumbers, SumOfPrime) {

    auto pm = Samples::ParallelMath();
    ASSERT_EQ(1060,pm.calculate_sum_primes(100));

}
TEST(SerialNaturalNumbers, SumOfPrime) {

    auto pm = Samples::SerialMath();
    ASSERT_EQ(1060,pm.calculate_sum_primes(100));

}
TEST(MultithreadNaturalNumbers, SumOfLargePrime) {

    auto pm = Samples::ParallelMath();
    ASSERT_EQ(1060,pm.calculate_sum_primes(100));
    ASSERT_EQ(454396537,pm.calculate_sum_primes(100000));
}
TEST(SerialNaturalNumbers, SumOfLargePrime) {

    auto pm = Samples::SerialMath();
    ASSERT_EQ(1060,pm.calculate_sum_primes(100));
    ASSERT_EQ(454396537,pm.calculate_sum_primes(100000));
}

TEST(MultithreadNaturalNumbers, IsNotPrime) {

    auto pm = Samples::ParallelMath();

    ASSERT_FALSE(pm.is_prime(4));
    ASSERT_FALSE(pm.is_prime(70));
    ASSERT_FALSE(pm.is_prime(7920));
}
TEST(SerialAlgebra,MatrixMultiplication){
    const size_t size=5;
    long ** A = (long **)malloc(size * sizeof(long *));
    if (A == nullptr) {
        exit(2);
    }
    for (size_t i=0; i<size; i++) {
        A[i] = (long *)malloc(size * sizeof(long));
        if (A[i] == nullptr) {
            exit(2);
        }
        for (size_t j=0; j<size; j++) {
            A[i][j] = 1;
        }
    }
    long ** B = (long **)malloc(size * sizeof(long *));
    if (B == nullptr) {
        exit(2);
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
    // allocate arrays for sequential and parallel results
    long ** sequential_result = (long **)malloc(size * sizeof(long *));
    if (sequential_result == nullptr) {
        exit(2);
    }
    for (size_t i=0; i<size; i++) {
        sequential_result[i] = (long *)malloc(size * sizeof(long));
        if (sequential_result[i] == nullptr) {
            exit(2);
        }
    }
    Samples::SerialMath::matrix_multiply(A, size, size, B, size, size, sequential_result);
    for (size_t i=0; i<size; i++) {
        for (size_t j=0; j<size; j++) {
            ASSERT_EQ(size,sequential_result[i][j]);
        }
    }
    for (size_t i=0; i<size; i++) {
        free(sequential_result[i]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}