//
// Created by Santiago Hurtado on 19.10.19.
//
#include <gtest/gtest.h>
#include "multithread/NaturalNumbers.h"

TEST(MultithreadNaturalNumbers, IsPrime) {
    ASSERT_TRUE(multithread::NaturalNumbers::is_prime(2));
    ASSERT_TRUE(multithread::NaturalNumbers::is_prime(3));
    ASSERT_TRUE(multithread::NaturalNumbers::is_prime(5));
    ASSERT_TRUE(multithread::NaturalNumbers::is_prime(7));
    ASSERT_TRUE(multithread::NaturalNumbers::is_prime(11));
}

TEST(MultithreadNaturalNumbers, IsNotPrime) {
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(0));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(1));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(4));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(6));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(8));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(9));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(10));
    ASSERT_FALSE(multithread::NaturalNumbers::is_prime(12));
}

TEST(MultithreadNaturalNumbers, ListOfPrimesLessThan10) {
    auto primeNumbers = multithread::NaturalNumbers();
    auto result = primeNumbers.calculate_sum_primes(10);
    ASSERT_EQ(17, result);
    for (auto it=primeNumbers.begin();it!=primeNumbers.end();++it) {
        ASSERT_TRUE(multithread::NaturalNumbers::is_prime(*it));
    }
}

TEST(MultithreadNaturalNumbers, ListOfPrimesLessThan100) {
    auto primeNumbers = multithread::NaturalNumbers();
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