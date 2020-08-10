//
// Created by Santiago Hurtado on 19.10.19.
//
#include <gtest/gtest.h>
#include "parallel/NaturalNumbers.h"
#include "multithread/NaturalNumbers.h"

TEST(ParallelNaturalNumbers, ListOfPrimesLessThan10) {
    auto primeNumbers = parallel::NaturalNumbers();
    auto result = primeNumbers.calculate_sum_primes(10);
    ASSERT_EQ(17, result);
    for (auto it=primeNumbers.begin();it!=primeNumbers.end();++it) {
        ASSERT_TRUE(multithread::NaturalNumbers::is_prime(*it));
    }
}

TEST(ParallelNaturalNumbers, ListOfPrimesLessThan100) {
    auto primeNumbers = parallel::NaturalNumbers();
    auto result = primeNumbers.calculate_sum_primes(100);
    ASSERT_EQ(1060, result);
    for (auto it=primeNumbers.begin();it!=primeNumbers.end();++it) {
        ASSERT_TRUE(multithread::NaturalNumbers::is_prime(*it));
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}