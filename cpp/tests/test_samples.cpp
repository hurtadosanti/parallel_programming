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
TEST(MultithreadNaturalNumbers, SumTo10) {
    auto sm = Samples::ParallelMath();
    auto values = std::vector<unsigned int>();
    for (int i = 0; i <=10 ;++i) {
        values.push_back(i);
    }
    ASSERT_EQ(55,sm.sum(values));
}

TEST(SerialNaturalNumbers, SumTo10) {
    auto sm = Samples::SerialMath();
    auto values = std::vector<unsigned int>();
    for (int i = 0; i <=10 ;++i) {
        values.push_back(i);
    }
    ASSERT_EQ(55,sm.sum(values));
}
TEST(SerialAlgebra,MatrixMultiplication){
    // Setup
    const size_t size=5;
    long ** A = nullptr;
    long ** B = nullptr;
    long ** sequential_result = nullptr;
    Samples::SerialMath::init_matrix(size,A,B,sequential_result);
    // Act
    Samples::SerialMath::matrix_multiply(A, size, size, B, size, size, sequential_result);
    // Serialize
    for (size_t i=0; i<size; i++) {
        for (size_t j=0; j<size; j++) {
            ASSERT_EQ(size,sequential_result[i][j]);
        }
    }
    // clean
    for (size_t i=0; i<size; i++) {
        free(sequential_result[i]);
        free(A[i]);
        free(B[i]);
    }
}
TEST(MultithreadAlgebra,MatrixMultiplication){
    // Setup
    const size_t size=5;
    long ** A = nullptr;
    long ** B = nullptr;
    long ** sequential_result = nullptr;
    Samples::ParallelMath::init_matrix(size,A,B,sequential_result);
    // Act
    Samples::ParallelMath::matrix_multiply(A, size, size, B, size, size, sequential_result);
    // Serialize
    for (size_t i=0; i<size; i++) {
        for (size_t j=0; j<size; j++) {
            ASSERT_EQ(size,sequential_result[i][j]);
        }
    }
    // clean
    for (size_t i=0; i<size; i++) {
        free(sequential_result[i]);
        free(A[i]);
        free(B[i]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}